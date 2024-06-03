#include <vector>
#include <cstdio>

using std::vector;
using std::printf;

/* Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
 * If x = 0, then return 0.
 */
int leftmost_one(unsigned x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    
    return x - (x >> 1);
}

int main() {
     vector<unsigned> testcases{
        0, 0xFE000000, 0x121, 0xFF00, 0x6600
     };

     for (auto o : testcases) {
        printf("%08X : %08X\n", o, leftmost_one(o));
     }

     return 0;
}