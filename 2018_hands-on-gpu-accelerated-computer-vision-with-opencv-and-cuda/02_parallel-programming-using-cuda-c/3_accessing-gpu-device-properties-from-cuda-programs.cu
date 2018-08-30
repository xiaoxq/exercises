#include <cuda_runtime.h>
#include <iostream>
#include <memory>

using namespace std;

void GeneralDeviceProperties(const int device) {
  cout << "===========================================================" << endl;
  cudaDeviceProp device_Property;
  cudaGetDeviceProperties(&device_Property, device);
  cout << "Device " << device << ": " << device_Property.name << endl;

  int driver_Version, runtime_Version;
  cudaDriverGetVersion(&driver_Version);
  cudaRuntimeGetVersion(&runtime_Version);
  cout << "CUDA Driver Version: "
       << driver_Version / 1000 << "." << (driver_Version % 100) / 10 << endl;
  cout << "CUDA Runtime Version: "
       << runtime_Version / 1000 << "." << (runtime_Version % 100) / 10 << endl;

  const int mem_mb = device_Property.totalGlobalMem >> 20;
  cout << "Total amount of global memory: " << mem_mb << "MB." << endl;

  cout << "Multiprocessors: " << device_Property.multiProcessorCount << endl;
  cout << "GPU Clock rate: " << device_Property.clockRate * 1e-6f << "GHz" << endl;
  cout << "===========================================================" << endl;
}

int main(void) {
  int device_count = 0;
  cudaGetDeviceCount(&device_count);
  cout << "CUDA Capable device(s): " << device_count << endl;

  for (int i = 0; i < device_count; ++i) {
    GeneralDeviceProperties(i);
  }
  return 0;
}
