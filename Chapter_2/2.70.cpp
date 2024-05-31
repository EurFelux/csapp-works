#include <vector>
#include <cstdio>
#include <tuple>

using std::printf;
using std::vector;

/* Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */
int fits_bits(int x, int n)
{
    const unsigned w = sizeof(int) << 3;

    // mask_flag = 0xff...ff if x is negative; otherwise mask_flag = 0.
    unsigned mask_flag = ~!!(x & (1 << (w - 1))) + 1;

    unsigned mask = ~0 << (n - 1);

    return (x & mask) == (mask & mask_flag);
}

int main()
{
    vector<std::tuple<int, int, int>> testcases{
        std::make_tuple(15, 5, 1),
        std::make_tuple(0, 5, 1),
        std::make_tuple(-15, 5, 1),
        std::make_tuple(31, 5, 0),
        std::make_tuple(31, 4, 0),
        std::make_tuple(-32, 5, 0),
        std::make_tuple(-1, 1, 1),
    };

    bool pass = true;

    for (int i = 0; i < testcases.size(); ++i)
    {
        int x = std::get<0>(testcases[i]);
        int n = std::get<1>(testcases[i]);
        int target = std::get<2>(testcases[i]);
        int res = fits_bits(x, n);
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