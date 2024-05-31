#include <vector>
#include <cstdio>
#include <utility>

using std::vector;
using std::printf;

/* Do rotating left shift.  Assume 0 <= n < w
 * Examples when x = 0x12345678 and w = 32:
 *      n=4 -> 0x23456781, n=20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n) {
    const unsigned w = sizeof(int) << 3;
    
    unsigned mask_zero_n = ~(!!n) + 1;
    unsigned mask_high_n = ~0 << ((w - n) & mask_zero_n);
    unsigned hign_n = x & mask_high_n;
    unsigned low_n = hign_n >> ((w - n) & mask_zero_n);

    return (x << n) | low_n;
}

int main() {
     vector<std::pair<unsigned, int>> testcases{
        {0x12345678, 4},
        {0x12345678, 20},
        {0x12345678, 0},
     };

     for (auto o : testcases) {
        printf("0x%08X\n", rotate_left(o.first, o.second));
     }

     return 0;
}