#include <cuda.h>
#include <cuda_runtime.h>
#include <stdio.h>
#include <iostream>

// TODO(xiaoxq): Fix the crash.

// Number of elements in Array
#define N 1000000

// Definition of kernel function to add two variables
__global__
void gpuAdd(int *d_a, int *d_b, int *d_c) {
  // gridDim.x    Grid width (Number of blocks)
  // blockDim.x   Block width (Size of a block)
  // blockIdx.x   Index of current block
  // threadIdx.x  Index of current thread in current block
  printf("gridDim.x = %d, blockDim.x = %d, blockIdx.x = %d, threadIdx.x = %d\n",
         gridDim.x, blockDim.x, blockIdx.x, threadIdx.x);
  for (int grid = 0; ; ++grid) {
    const int tid = threadIdx.x + blockDim.x * (blockIdx.x + grid * gridDim.x);
    if (tid < N) {
      d_c[tid] = d_a[tid] + d_b[tid];
    } else {
      return;
    }
  }
}

int main(void) {
  // Declare host and device Arrays
  int h_a[N], h_b[N], h_c[N];
  for (int i = 0; i < N; i++) {
    h_a[i] = 2 * i * i;
    h_b[i] = i;
  }

  int *d_a, *d_b, *d_c;
  cudaMalloc((void**)&d_a, N * sizeof(int));
  cudaMalloc((void**)&d_b, N * sizeof(int));
  cudaMalloc((void**)&d_c, N * sizeof(int));

  cudaMemcpy(d_a, h_a, N * sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b, N * sizeof(int), cudaMemcpyHostToDevice);

  std::cout << "gpuAdd started." << std::endl;
  gpuAdd <<<512, 256>>>(d_a, d_b, d_c);
  cudaMemcpy(h_c, d_c, N * sizeof(int), cudaMemcpyDeviceToHost);
  cudaDeviceSynchronize();
  std::cout << "gpuAdd ended." << std::endl;

  bool correct = true;
  for (int i = 0; i < N; i++) {
    if ((h_a[i] + h_b[i] != h_c[i])) {
      correct = false;
      break;
    }
  }

  std::cout << (correct ? "Finished successfully!"
                        : "Finished with error!") << std::endl;

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);
  return 0;
}
