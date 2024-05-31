#include <cstdio>

unsigned long long generate(int x, int y) {
    unsigned long long mask = 0xFF;
    return (x & mask) | (y & ~mask);
}

int main() {
    std::printf("0x%llX\n", generate(0x89ABCDEF, 0x76543210)); // 765432EF

    return 0;
}