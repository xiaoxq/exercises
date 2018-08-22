#include <cuda.h>
#include <cuda_runtime.h>
#include <iostream>

//Defining number of elements in Array
#define N 5

//Defining Kernel function for vector addition
__global__
void gpuAdd(int *d_a, int *d_b, int *d_c) {
  // Getting block index of current kernel
  int tid = blockIdx.x;  // handle the data at this index
  if (tid < N) {
    d_c[tid] = d_a[tid] + d_b[tid];
  }
}

int main() {
  int h_a[N], h_b[N], h_c[N];
  for (int i = 0; i < N; i++) {
    h_a[i] = 2 * i * i;
    h_b[i] = i ;
  }

  int *d_a, *d_b, *d_c;
  cudaMalloc((void**)&d_a, N * sizeof(int));
  cudaMalloc((void**)&d_b, N * sizeof(int));
  cudaMalloc((void**)&d_c, N * sizeof(int));

  // Copy data, do the calculation, and copy back.
  cudaMemcpy(d_a, h_a, N * sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b, N * sizeof(int), cudaMemcpyHostToDevice);
  gpuAdd <<<N, 1>>>(d_a, d_b, d_c);
  cudaMemcpy(h_c, d_c, N * sizeof(int), cudaMemcpyDeviceToHost);

  // Printing result on console
  for (int i = 0; i < N; i++) {
    std::cout << i << ": " << h_a[i] << " + " << h_b[i] << " = " << h_c[i]
              << std::endl;
  }

  // Free up memory
  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);
  return 0;
}
