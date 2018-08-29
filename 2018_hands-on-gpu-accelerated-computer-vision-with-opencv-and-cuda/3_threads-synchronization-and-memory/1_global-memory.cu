#include <iostream>

#define N 5

__global__
void gpu_global_memory(int *d_a) {
  d_a[threadIdx.x] = threadIdx.x;
}

int main(int argc, char **argv) {
  int h_a[N];
  int *d_a;

  const size_t kMemSize = sizeof(int) * N;
  cudaMalloc((void **)&d_a, kMemSize);
  cudaMemcpy((void *)d_a, (void *)h_a, kMemSize, cudaMemcpyHostToDevice);

  gpu_global_memory <<<1, N>>>(d_a);
  cudaMemcpy((void *)h_a, (void *)d_a, kMemSize, cudaMemcpyDeviceToHost);

  std::cout  << "Array in Global Memory is:" << std::endl;
  for (int i = 0; i < N; i++) {
    std::cout  << "At Index: " << i << " --> " << h_a[i] << std::endl;
  }
  return 0;
}
