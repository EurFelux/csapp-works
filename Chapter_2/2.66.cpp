#include <vector>
#include <cstdio>

using std::vector;
using std::printf;

/* Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
 * If x = 0, then return 0.
 */
int leftmost_one(unsigned x) {
    
    
    return 0;
}

int main() {
     vector<unsigned> testcases{
        0, 0xFE000000, 0x121
     };

     for (auto o : testcases) {
        printf("%08X : %u\n", o, odd_ones(o));
     }

     return 0;
}