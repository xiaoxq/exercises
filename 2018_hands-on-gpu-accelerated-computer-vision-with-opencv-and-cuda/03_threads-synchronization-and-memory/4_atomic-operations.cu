#include <iostream>

#define BLOCKS 100
#define THREADS 100
#define ARRAY_SIZE 10

__global__
void gpu_increment_without_atomic(int *d_a) {
  const int tid = (blockIdx.x * blockDim.x + threadIdx.x) % ARRAY_SIZE;
  d_a[tid] += 1;
}

__global__
void gpu_increment_atomic(int *d_a) {
  const int tid = (blockIdx.x * blockDim.x + threadIdx.x) % ARRAY_SIZE;
  atomicAdd(&d_a[tid], 1);
}

int main(int argc, char **argv) {
  const int MEM_SIZE = ARRAY_SIZE * sizeof(int);

  int h_a[ARRAY_SIZE];
  int* d_a;
  cudaMalloc((void **)&d_a, MEM_SIZE);

  // Calculate without atomic.
  cudaMemset((void *)d_a, 0, MEM_SIZE);
  gpu_increment_without_atomic <<<BLOCKS, THREADS>>>(d_a);
  cudaMemcpy(h_a, d_a, MEM_SIZE, cudaMemcpyDeviceToHost);
  std::cout << "Without atomic:" << std::endl;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    std::cout << "h_a[" << i << "] = " << h_a[i] << std::endl;
  }

  // Calculate with atomic.
  cudaMemset((void *)d_a, 0, MEM_SIZE);
  gpu_increment_atomic <<<BLOCKS, THREADS>>>(d_a);
  cudaMemcpy(h_a, d_a, MEM_SIZE, cudaMemcpyDeviceToHost);
  std::cout << "With atomic:" << std::endl;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    std::cout << "h_a[" << i << "] = " << h_a[i] << std::endl;
  }

  cudaFree(d_a);
  return 0;
}