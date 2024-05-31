#include <vector>
#include <cstdio>
#include <tuple>
#include <climits>

using std::printf;
using std::vector;

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y) {
    int sum = x + y;

    const unsigned w = sizeof(int) << 3;

    // cond_1 = x > 0 && y > 0 && sum < 0;

    // mask_flag_x = 0xFF...FF if x > 0; otherwise mask_flag_x = 0.
    unsigned mask_flag_x = ~(!(x & (1 << (w - 1))) && x) + 1;
    unsigned mask_flag_y = ~(!(y & (1 << (w - 1))) && y) + 1;

    // mask_flag_xy = 0xFF...FF if x+y < 0; otherwise mask_flag_xy = 0.
    unsigned mask_flag_xy = ~(!!(sum & (1 << (w - 1)))) + 1;

    // mask_pos_overflow = 0xFF...FF if cond_1 satisfies; otherwise 0.
    unsigned mask_pos_overflow = ~0 & mask_flag_x & mask_flag_y & mask_flag_xy;
    
    // cond_2 = x < 0 && y < 0 && sum >= 0
    
    // mask_flag_x = 0xFF...FF if x < 0; otherwise 0.
    mask_flag_x = ~(!!(x & (1 << (w - 1)))) + 1;
    mask_flag_y = ~(!!(y & (1 << (w - 1)))) + 1;

    // mask_flag_xy = 0xFF...FF if x+y >= 0; otherwise mask_flag_xy = 0.
    mask_flag_xy = ~!(sum & (1 << (w - 1))) + 1;

    // mask_neg_overflow = 0xFF...FF if cond_2 satisfies; otherwise 0.
    unsigned mask_neg_overflow = ~0 & mask_flag_x & mask_flag_y & mask_flag_xy;

    return (sum & (~0 ^ (mask_pos_overflow | mask_neg_overflow)))
           | (INT_MAX & mask_pos_overflow) | (INT_MIN & mask_neg_overflow);
}

int main()
{
    // int32
    vector<std::tuple<int, int, int>> testcases{
        std::make_tuple(1 << 30, 1 << 30, INT_MAX),
        std::make_tuple(INT_MIN, -1, INT_MIN),
        std::make_tuple(123, 456, 123+456),

    };

    bool pass = true;

    for (int i = 0; i < testcases.size(); ++i)
    {
        int x = std::get<0>(testcases[i]);
        int y = std::get<1>(testcases[i]);
        int target = std::get<2>(testcases[i]);
        auto res = saturating_add(x, y);

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