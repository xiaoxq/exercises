#include <cuda.h>
#include <cuda_runtime.h>

#include <iostream>

// Defining two constants
__constant__ int constant_f;
__constant__ int constant_g;

#define N 5

__global__
void gpu_constant_memory(float *d_in, float *d_out) {
  // Getting thread index for current kernel
  const int tid = threadIdx.x; 
  d_out[tid] = constant_f * d_in[tid] + constant_g;
}

int main(void) {
  // Copy constants to constant memory
  int h_f = 2, h_g = 20;
  cudaMemcpyToSymbol(constant_f, &h_f, sizeof(int), 0, cudaMemcpyHostToDevice);
  cudaMemcpyToSymbol(constant_g, &h_g, sizeof(int));
  
  float *d_in, *d_out;
  // Allocate the memory on the cpu.
  const size_t kMemSize = N * sizeof(float);
  cudaMalloc((void**)&d_in, kMemSize);
  cudaMalloc((void**)&d_out, kMemSize);

  // Copy Array from host to device.
  const float h_in[N] = {0, 1, 2, 3, 4};
  cudaMemcpy(d_in, h_in, kMemSize, cudaMemcpyHostToDevice);
  gpu_constant_memory <<<1, N>>>(d_in, d_out);

  // Coping result back to host from device memory
  float h_out[N];
  cudaMemcpy(h_out, d_out, kMemSize, cudaMemcpyDeviceToHost);
  
  // Printing result on console
  for (int i = 0; i < N; i++) {
    std::cout << "h_in / h_out[" << i << "] = " << h_in[i] << " / " << h_out[i]
              << std::endl;
  }

  cudaFree(d_in);
  cudaFree(d_out);
  return 0;
}