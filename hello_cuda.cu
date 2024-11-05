#include <iostream>
__global__ void helloCUDA() {
    printf("Hello from the GPU!\n");
}

int main() {
    helloCUDA<<<1, 1>>>();
    cudaDeviceSynchronize();
    return 0;
}

