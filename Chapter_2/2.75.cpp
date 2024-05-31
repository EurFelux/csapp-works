#include <vector>
#include <cstdio>
#include <tuple>
#include <climits>
#include <cstdint>

using std::printf;
using std::vector;

int signed_high_prod(int x, int y) {
    // 为了方便实现，就先假设是32位int
    long long prod = (long long) x * y;
    return (prod & 0xffffffff00000000) >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    return signed_high_prod(x, y);
}

int main()
{
    // int32
    vector<std::tuple<unsigned, unsigned, unsigned>> testcases{
        std::make_tuple(1 << 16, 1 << 16, 1),
        std::make_tuple(123, 456, 0),
    };

    bool pass = true;

    for (int i = 0; i < testcases.size(); ++i)
    {
        unsigned x = std::get<0>(testcases[i]);
        unsigned y = std::get<1>(testcases[i]);
        unsigned target = std::get<2>(testcases[i]);
        auto res = unsigned_high_prod(x, y);

        if (res != target)
        {
            printf("Test %d failed. Expectd %08X but got %08X. \n", i, target, res);
            pass = false;
        }
    }
    
    if (pass)
    {
        printf("All tests passed.\n");
    }

    return 0;
}