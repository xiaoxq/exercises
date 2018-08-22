#include <stdio.h>
#include <iostream>

__global__
void myfirstkernel(void) {
  // blockIdx.x gives the block number of current kernel
  printf("Hello! I'm thread in block: %d\n", blockIdx.x);
}

int main() {
  // A kernel call with 16 blocks and 1 thread per block
  myfirstkernel <<<16, 1>>>();

  // Function used for waiting for all kernels to finish
  cudaDeviceSynchronize();

  std::cout << "All threads are finished!" << std::endl;
  return 0;
}
