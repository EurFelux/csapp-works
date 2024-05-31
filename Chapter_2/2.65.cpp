#include <vector>
#include <cstdio>

using std::vector;
using std::printf;

/* Return 1 when x contains an odd number of 1s; 0 otherwise.
   Assume w=32 */
int odd_ones(unsigned x) {
    int num_one = 0u;
    
    return num_one % 2;
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