#include <cuda.h>
#include <cuda_runtime.h>

#include <iostream>

int main() {
  cudaEvent_t e_start, e_stop;
  cudaEventCreate(&e_start);
  cudaEventCreate(&e_stop);
  cudaEventRecord(e_start, 0);

  int *d_a;
  const int MEM_SIZE = 2048;
  cudaMalloc((void**)&d_a, MEM_SIZE);
  cudaMemset((void *)d_a, 0, MEM_SIZE);

  cudaDeviceSynchronize();
  cudaEventRecord(e_stop, 0);
  cudaEventSynchronize(e_stop);

  float elapsedTime;
  cudaEventElapsedTime(&elapsedTime, e_start, e_stop);
  std::cout << "Elapsed time: " << elapsedTime << std::endl;
  return 0;
}
