#include "device_launch_parameters.h"
#include <stdio.h>

#define arraySize 5
#define threadPerBlock 5

// Kernel Function for Rank sort
__global__
void addKernel(int *d_in, int *d_out) {
  int count = 0;
  int tid = threadIdx.x;
  int ttid = blockIdx.x * threadPerBlock + tid;
  int val = d_in[ttid];
  __shared__ int cache[threadPerBlock];
  for (int i = tid; i < arraySize; i += threadPerBlock) {
    cache[tid] = d_in[i];
    __syncthreads();
    for (int j = 0; j < threadPerBlock; ++j) {
      if (val > cache[j]) {
        ++count;
      }
    }
    __syncthreads();
  }
  d_out[count] = val;
}

int main() {
  const size_t kMemSize = arraySize * sizeof(int);
  // Define Host and Device Array
  int h_in[arraySize] = {5, 9, 3, 4, 8};
  int h_out[arraySize];

  // Allocate Memory on the device 
  int *d_in, *d_out;
  cudaMalloc((void**)&d_in, kMemSize);
  cudaMalloc((void**)&d_out, kMemSize);

  // Copy input vector from host memory to device memory.
  cudaMemcpy(d_in, h_in, kMemSize, cudaMemcpyHostToDevice);

  // Launch a kernel on the GPU with one thread for each element.
  addKernel <<<arraySize / threadPerBlock, threadPerBlock>>>(d_in, d_out);

  // Wait for device to finish operations
  cudaDeviceSynchronize();
  // Copy output vector from GPU buffer to host memory.
  cudaMemcpy(h_out, d_out, kMemSize, cudaMemcpyDeviceToHost);
  printf("The Enumeration sorted Array is: \n");
  for (int i = 0; i < arraySize; i++) {
    printf("%d\n", h_b[i]);
  }
  // Free up device memory
  cudaFree(d_in);
  cudaFree(d_out);
  return 0;
}
