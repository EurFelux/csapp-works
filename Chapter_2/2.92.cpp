#include <cstdio>
#include <cmath>

typedef unsigned float_bits;

/* Compute -f.  If f is NaN, then return f. */
float_bits float_negate(float_bits f) {
    unsigned mask_exp = 0x7F800000;
    unsigned mask_frac = 0x007FFFFF;
    unsigned mask_sign = 0x80000000;
    bool nan = ((f & mask_exp) == mask_exp) && ((f & mask_frac) != 0);
    if (nan)
        return f;

    return f ^ mask_sign;
}

float u2f(unsigned x) {
    union {
        unsigned u;
        float f;
    } u;
    u.u = x;
    return u.f;
}

bool testcase(float_bits u)
{
    float_bits res = float_negate(u);
    float target = -u2f(u);
    if (u2f(res) != target && !(isnanf(u2f(res)) && isnanf(target))) {
        printf("Test failed. u = %08X. %08X should be %08X.\n", u, res, target);
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    for (float_bits u = 0; u < __UINT32_MAX__; ++u) {
        if (!testcase(u)) break;
    }

    testcase(__UINT32_MAX__);

    printf("Test completed.\n");
    return 0;
}
