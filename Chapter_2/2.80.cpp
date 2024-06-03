#include <vector>
#include <cstdio>
#include <climits>

using std::vector;
using std::printf;

int threefourths(int x) {
    const unsigned w = sizeof(int) << 3;
    
    // >> 2 with round (/4)
    int mask = (x & (1 << (w - 1))) >> (w - 1);
    int res = (x + (((1 << 2) - 1) & mask)) >> 2;

    // *3
    res = (res << 1) + res;

    // add error
    res += ((x & 0b11) - 1) & (~!!(x & 0b11) + 1);
    
    return res;
}

int main() {
     vector<int> testcases{
        0, INT_MIN, INT_MAX, 0x12345678
     };

     for (int i = 0; i < testcases.size(); ++i) {
        auto o = testcases[i];
        auto res = threefourths(o);
        int target = 0.75 * o;
        if (res != target)
            printf("Test %d failed. Expected %d but got %d.\n", i, target, res);
     }

     return 0;
}