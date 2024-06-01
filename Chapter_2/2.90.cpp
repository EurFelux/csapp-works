#include <vector>
#include <cstdio>
#include <tuple>
#include <cmath>

using std::vector;
using std::printf;

float u2f(unsigned x)
{
    union {
        unsigned u;
        float f;
    } u;
    u.u = x;
    return u.f;
}

float fpwr2(int x)
{
    unsigned exp, frac;
    unsigned u;

    if (x < -149) {
        /* Too small.  Return 0.0 */
        exp = 0;
        frac = 0;
    } else if (x < -126) {
        /* Denormalized result */
        exp = 0;
        frac = 1 << (149 + x);
    } else if (x < 128) {
        /* Normalized result. */
        exp = x + 127;
        frac = 0;
    } else {
        /* Too big.  Return +oo */
        exp = ~(~0 << 8);
        frac = 0;
    }

    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;

    /* Return as float */
    return u2f(u);
}

int main() {
    vector<int> testcases {
        -150, -120, 0, 4, 127, 128
    };

    bool pass = true;

    for (int i = 0; i < testcases.size(); ++i) {
        auto x = testcases[i];
        auto res = fpwr2(x);
        float target = (float) pow(2, x);
        if (res - target > 1e-6) {
            printf("Test %d not passed.\n");
            printf("\t result: %f\n", res);
            printf("\t target: %f\n", target);
            pass = false;
        }
    }
    if (pass)
        printf("All tests passed.\n");

    return 0;
}