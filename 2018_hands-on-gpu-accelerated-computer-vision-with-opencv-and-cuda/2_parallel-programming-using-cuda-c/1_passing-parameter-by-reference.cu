#include <iostream>

#include <cuda.h>
#include <cuda_runtime.h>

// Kernel function to add two variables, parameters are passed by reference
__global__
void gpuAdd(int *d_a, int *d_b, int *d_c) {
  *d_c = *d_a + *d_b;
}

int main() {
  // Defining host and variables
  int h_a = 1, h_b = 2, h_c;
  int *d_a, *d_b, *d_c;
  // Allocating memory for Device Pointers
  cudaMalloc((void**)&d_a, sizeof(int));
  cudaMalloc((void**)&d_b, sizeof(int));
  cudaMalloc((void**)&d_c, sizeof(int));
  // Coping value of host variables in device memory
  cudaMemcpy(d_a, &h_a, sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, &h_b, sizeof(int), cudaMemcpyHostToDevice);

  // Calling kernel with one thread and one block with parameters passed by reference
  gpuAdd<<<1, 1>>>(d_a, d_b, d_c);
  // Coping result from device memory to host
  cudaMemcpy(&h_c, d_c, sizeof(int), cudaMemcpyDeviceToHost);
  std::cout << "Passing Parameter by Reference Output: "
            << h_a << " + " << h_b << " = " << h_c << std::endl;

  // Free up memory
  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);
  return 0;
}
