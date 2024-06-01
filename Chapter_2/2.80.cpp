#include <vector>
#include <cstdio>

using std::vector;
using std::printf;

int threefourths(int x) {
    return 3 * x / 4;
}

int main() {
     vector<int> testcases{
        1, 2, 3
     };

     for (int i = 0; i < testcases.size(); ++i) {
        auto o = testcases[i];
        auto res = threefourths(o);
        auto target = 3 * o / 4;
        if (res != target)
            printf("Test %d failed. Expected %d but got %d.\n", i, target, res);
     }

     return 0;
}