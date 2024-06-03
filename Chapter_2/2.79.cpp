#include <vector>
#include <cstdio>
#include <climits>

using std::vector;
using std::printf;

int mul3div4(int x) {
    const unsigned w = sizeof(int) << 3;
    int mask = (x & (1 << (w - 1))) >> (w - 1);
    
    x = ((x << 1) + x);
    return (x + (((1 << 2) - 1) & mask)) >> 2;
}

int main() {
     vector<int> testcases{
        0x7fffffff, INT_MIN, 3, -6
     };

     bool pass = true;

     for (int i = 0; i < testcases.size(); ++i) {
        auto o = testcases[i];
        auto res = mul3div4(o);
        auto target = 3 * o / 4;
        if (res != target) {
            printf("Test %d failed. Expected %d but got %d.\n", i, target, res);
            pass = false;
        }
     }

     if (pass) {
        printf("All tests passed.\n");
     }

     return 0;
}