#include <vector>
#include <cstdio>

using std::vector;
using std::printf;

/* Return 1 when any odd bit of x equals 1; 0 otherwise.
   Assume w=32 */
int any_odd_one(unsigned x) {
    return !!(x & 0x55555555);
}

int main() {
     vector<unsigned> testcases{
        0b0000u, 0b0101u, 0b1010u
     };

     for (auto o : testcases) {
        printf("%02X : %d\n", o, any_odd_one(o));
     }

     return 0;
}