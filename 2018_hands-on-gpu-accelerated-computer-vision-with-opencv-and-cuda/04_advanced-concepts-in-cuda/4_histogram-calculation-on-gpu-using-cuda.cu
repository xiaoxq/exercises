#include <cuda_runtime.h>

#include <iostream>

#define SIZE 1000
#define NUM_BIN 16

__global__
void histogram_atomic(int *d_b, int *d_a) {
  int tid = threadIdx.x + blockDim.x * blockIdx.x;
  int item = d_a[tid];
  if (tid < SIZE) {
    atomicAdd(&(d_b[item]), 1);
  }
}

__global__
void histogram_shared_memory(int *d_b, int *d_a) {
  __shared__ int cache[256];
  cache[threadIdx.x] = 0;
  __syncthreads();

  for (int tid = threadIdx.x + blockDim.x * blockIdx.x; tid < SIZE;
       tid += blockDim.x * gridDim.x) {
    atomicAdd(&(cache[d_a[tid]]), 1);
  }
  __syncthreads();
  atomicAdd(&(d_b[threadIdx.x]), cache[threadIdx.x]);
}

int main() {
  int h_a[SIZE];
  for (int i = 0; i < SIZE; i++) {
    h_a[i] = i % NUM_BIN;
  }
  int h_b[NUM_BIN];
  for (int i = 0; i < NUM_BIN; i++) {
    h_b[i] = 0;
  }

  // declare GPU memory pointers
  int *d_a;
  int *d_b;

  // allocate GPU memory
  cudaMalloc((void **)&d_a, SIZE * sizeof(int));
  cudaMalloc((void **)&d_b, NUM_BIN * sizeof(int));

  // transfer the arrays to the GPU
  cudaMemcpy(d_a, h_a, SIZE * sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b, NUM_BIN * sizeof(int), cudaMemcpyHostToDevice);

  // launch the kernel
  // histogram_atomic << <((SIZE+NUM_BIN-1) / NUM_BIN), NUM_BIN >> >(d_b, d_a);
  const int blocks = (SIZE + NUM_BIN - 1) / NUM_BIN;
  histogram_shared_memory <<<blocks, NUM_BIN>>> (d_b, d_a);

  // copy back the sum from GPU
  cudaMemcpy(h_b, d_b, NUM_BIN * sizeof(int), cudaMemcpyDeviceToHost);
  for (int i = 0; i < NUM_BIN; i++) {
    std::cout << "h_b[" << i << "] = " << h_b[i] << std::endl;
  }

  // free GPU memory allocation
  cudaFree(d_a);
  cudaFree(d_b);
  return 0;
}
