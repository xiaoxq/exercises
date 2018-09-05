#include <cuda_runtime.h>

#include <iostream>

#define ARRAY_SIZE 5
#define THREADS_PER_BLOCK 5
#define BLOCKS (ARRAY_SIZE / THREADS_PER_BLOCK)


// Kernel Function for Rank sort.
__global__
void addKernel(int *d_in, int *d_out) {
  int count = 0;
  const int val = d_in[blockIdx.x * THREADS_PER_BLOCK + threadIdx.x];
  __shared__ int cache[THREADS_PER_BLOCK];
  for (int i = threadIdx.x; i < ARRAY_SIZE; i += THREADS_PER_BLOCK) {
    cache[threadIdx.x] = d_in[i];
    __syncthreads();
    for (int j = 0; j < THREADS_PER_BLOCK; ++j) {
      if (val > cache[j]) {
        ++count;
      }
    }
    __syncthreads();
  }
  d_out[count] = val;
}

int main() {
  const size_t kMemSize = ARRAY_SIZE * sizeof(int);
  // Define Host and Device Array.
  int h_in[ARRAY_SIZE] = {5, 9, 3, 4, 8};
  int h_out[ARRAY_SIZE];

  // Allocate Memory on the device.
  int *d_in, *d_out;
  cudaMalloc((void**)&d_in, kMemSize);
  cudaMalloc((void**)&d_out, kMemSize);

  // Copy input vector from host memory to device memory.
  cudaMemcpy(d_in, h_in, kMemSize, cudaMemcpyHostToDevice);

  // Launch a kernel on the GPU with one thread for each element.
  addKernel <<<BLOCKS, ARRAY_SIZE / BLOCKS>>>(d_in, d_out);

  // Wait for device to finish operations.
  cudaDeviceSynchronize();

  // Copy output vector from GPU buffer to host memory.
  cudaMemcpy(h_out, d_out, kMemSize, cudaMemcpyDeviceToHost);
  for (size_t i = 0; i < ARRAY_SIZE; ++i) {
    std::cout << h_out[i] << std::endl;
  }

  // Free up device memory.
  cudaFree(d_in);
  cudaFree(d_out);
  return 0;
}
