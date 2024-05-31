#include <cstdio>

using namespace std;

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned mask_1 = b << i*8;
    unsigned mask_2 = 0xff << i*8;
    return x & ~mask_2 | mask_1;

}

void test(unsigned x, int i, unsigned char b) {
    std::printf("0x%X\n", replace_byte(x, i, b));

}

int main() {
    test(0x12345678, 2, 0xab);
    test(0x12345678, 0, 0xab);
    return 0;
}