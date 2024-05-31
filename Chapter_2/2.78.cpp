#include <vector>
#include <cstdio>
#include <tuple>
#include <climits>
#include <cstdint>

using std::printf;
using std::vector;

/* Divide by power of 2. Assume 0 <= k < w-1*/
int divide_power2(int x, int k) {
    const unsigned w = sizeof(int) << 3;
    int mask = (x & (1 << (w - 1))) >> (w - 1);
    
    // x >= 0: x >> k
    // x <  0: (x + (1 << k) - 1) >> k
    return (x + (((1 << k) - 1) & mask)) >> k;
}

int main()
{
    // int32
    vector<std::tuple<int, int, int>> testcases{
        std::make_tuple(1024, 3, 1 << 7),
        std::make_tuple(123, 2, 30),
        std::make_tuple(-123, 2, -30),
        std::make_tuple(-123, 0, -123),
    };

    bool pass = true;

    for (int i = 0; i < testcases.size(); ++i)
    {
        auto x = std::get<0>(testcases[i]);
        auto y = std::get<1>(testcases[i]);
        auto target = std::get<2>(testcases[i]);
        auto res = divide_power2(x, y);

        if (res != target)
        {
            printf("Test %d failed. Expectd %d but got %d. \n", i, target, res);
            pass = false;
        }
    }
    
    if (pass)
    {
        printf("All tests passed.\n");
    }

    return 0;
}