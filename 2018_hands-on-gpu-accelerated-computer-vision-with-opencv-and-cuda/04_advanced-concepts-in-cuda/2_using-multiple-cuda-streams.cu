#include <cuda.h>
#include <cuda_runtime.h>

#include <iostream>

// Defining number of elements in Array
#define N 50000

// Defining Kernel function for vector addition
__global__
void gpuAdd(int *d_a, int *d_b, int *d_c) {
  for (int tid = threadIdx.x + blockIdx.x * blockDim.x;
       tid < N; tid += blockDim.x * gridDim.x) {
    d_c[tid] = d_a[tid] + d_b[tid];
  }
}

int main(void) {
  const size_t kSizeOfNInt = N * sizeof(int);

  // Defining host arrays
  int *h_a, *h_b, *h_c;
  cudaHostAlloc((void**)&h_a, 2 * kSizeOfNInt, cudaHostAllocDefault);
  cudaHostAlloc((void**)&h_b, 2 * kSizeOfNInt, cudaHostAllocDefault);
  cudaHostAlloc((void**)&h_c, 2 * kSizeOfNInt, cudaHostAllocDefault);
  for (int i = 0; i < N * 2; i++) {
    h_a[i] = 2 * i * i;
    h_b[i] = i;
  }

  // Defining device pointers for stream 0
  int *d_a0, *d_b0, *d_c0;
  cudaMalloc((void**)&d_a0, kSizeOfNInt);
  cudaMalloc((void**)&d_b0, kSizeOfNInt);
  cudaMalloc((void**)&d_c0, kSizeOfNInt);

  // Defining device pointers for stream 1
  int *d_a1, *d_b1, *d_c1;
  cudaMalloc((void**)&d_a1, kSizeOfNInt);
  cudaMalloc((void**)&d_b1, kSizeOfNInt);
  cudaMalloc((void**)&d_c1, kSizeOfNInt);

  // Init streams.
  cudaStream_t stream0, stream1;
  cudaStreamCreate(&stream0);
  cudaStreamCreate(&stream1);

  // Asynchrnous Memory Copy Operation for both streams
  cudaMemcpyAsync(d_a0, h_a , kSizeOfNInt, cudaMemcpyHostToDevice, stream0);
  cudaMemcpyAsync(d_a1, h_a + N, kSizeOfNInt, cudaMemcpyHostToDevice, stream1);
  cudaMemcpyAsync(d_b0, h_b , kSizeOfNInt, cudaMemcpyHostToDevice, stream0);
  cudaMemcpyAsync(d_b1, h_b + N, kSizeOfNInt, cudaMemcpyHostToDevice, stream1);

  // Kernel call
  gpuAdd <<<512, 512, 0, stream0>>> (d_a0, d_b0, d_c0);
  gpuAdd <<<512, 512, 0, stream1>>> (d_a1, d_b1, d_c1);

  // Copy result back to host memory from device memory
  cudaMemcpyAsync(h_c , d_c0, kSizeOfNInt, cudaMemcpyDeviceToHost, stream0);
  cudaMemcpyAsync(h_c + N, d_c1, kSizeOfNInt, cudaMemcpyDeviceToHost, stream0);

  cudaDeviceSynchronize();
  cudaStreamSynchronize(stream0);
  cudaStreamSynchronize(stream1);

  // Check result.
  const int idx = N / 2;
  std::cout << "h_a[" << idx << "] = " << h_a[idx] << std::endl;
  std::cout << "h_b[" << idx << "] = " << h_b[idx] << std::endl;
  std::cout << "h_c[" << idx << "] = " << h_c[idx] << std::endl;

  // Free up memory
  cudaFree(d_a0);
  cudaFree(d_b0);
  cudaFree(d_c0);
  cudaFree(d_a0);
  cudaFree(d_b0);
  cudaFree(d_c0);
  cudaFreeHost(h_a);
  cudaFreeHost(h_b);
  cudaFreeHost(h_c);
  return 0;
}
