#include <iostream>

__global__
void myfirstkernel(void) {
}

int main(void) {
  myfirstkernel<<<1, 1>>>();
  std::cout << "Hello, CUDA!" << std::endl;
  return 0;
}
