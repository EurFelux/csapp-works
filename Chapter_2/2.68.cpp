#include <vector>
#include <cstdio>

using std::vector;
using std::printf;

/* Mask with least significant n bits set to 1
 * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 */
int lower_one_mask(int n) {
    unsigned w = sizeof(int) << 3;
    unsigned mask_n = ~(n != w) + 1;
    return (~0 << (n & mask_n)) ^ mask_n;
}

int main() {
     vector<int> testcases{
        6, 17, 32
     };

     for (auto o : testcases) {
        printf("%d : %08X\n", o, lower_one_mask(o));
     }

     return 0;
}