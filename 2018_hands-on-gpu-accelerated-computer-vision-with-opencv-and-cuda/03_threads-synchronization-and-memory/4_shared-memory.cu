#include <iostream>

#define N 5

__global__
void gpu_shared_memory(float *d_a) {
  int i, index = threadIdx.x;
  float sum = 0.0f;

  // Defining shared memory.
  __shared__ float sh_arr[10];
  sh_arr[index] = d_a[index];

  // This directive ensure all the writes to shared memory have completed.
  __syncthreads();
  for (i = 0; i<= index; i++) { 
    sum += sh_arr[i]; 
  }
  const float average = sum / (index + 1.0f);
  d_a[index] = average;
  // This statement is redundant and will have no effect on overall execution.
  sh_arr[index] = 0;
}

int main(int argc, char **argv) {
  float h_a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  float *d_a;

  // Allocate global memory on the device.
  const size_t kMemSize = sizeof(float) * 10;
  cudaMalloc((void **)&d_a, kMemSize);
  cudaMemcpy((void *)d_a, (void *)h_a, kMemSize, cudaMemcpyHostToDevice);

  gpu_shared_memory <<<1, 10>>>(d_a);
  cudaMemcpy((void *)h_a, (void *)d_a, kMemSize, cudaMemcpyDeviceToHost);

  for (int i = 0; i < 10; i++) {
    std::cout << "The running average after " << i << " element is "
              << h_a[i] << std::endl;
  }
  return 0;
}
