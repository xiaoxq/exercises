#include <cuda.h>
#include <cuda_runtime.h>

#include <iostream>

#define BLOCKS 10
#define THREADS 10

// Define texture reference for 1-d access
texture <float, 1, cudaReadModeElementType> textureRef;

__global__
void gpu_texture_memory(int n, float *d_out) {
  const int idx = blockIdx.x * blockDim.x + threadIdx.x;
  if (idx < n) {
    d_out[idx] = tex1D(textureRef, float(idx));
  }
}

int main() {
  const size_t N = BLOCKS * THREADS;
  const size_t kMemSize = sizeof(float) * N;
  float *d_out;
  cudaMalloc((void**)&d_out, kMemSize);

  // Allocate space on the host for the results
  float h_in[N];
  for (int i = 0; i < N; i++) {
    h_in[i] = float(i);
  }
  float *h_out = (float*)malloc(kMemSize);

  // Define CUDA Array
  cudaArray *cu_Array;
  cudaMallocArray(&cu_Array, &textureRef.channelDesc, N, 1);
  cudaMemcpyToArray(cu_Array, 0, 0, h_in, kMemSize, cudaMemcpyHostToDevice);

  // Bind a texture to the CUDA array
  cudaBindTextureToArray(textureRef, cu_Array);
  gpu_texture_memory <<<BLOCKS, THREADS>>>(N, d_out);

  cudaMemcpy(h_out, d_out, sizeof(float)*N, cudaMemcpyDeviceToHost);
  for (int i = 0; i < N; i++) {
    std::cout << "Average between two nearest elements is: "
              << h_out[i] << std::endl;
  }
  free(h_out);
  cudaFree(d_out);
  cudaFreeArray(cu_Array);
  cudaUnbindTexture(textureRef);
  return 0;
}
