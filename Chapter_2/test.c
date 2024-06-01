#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef unsigned float_bits;

/* Compute -f.  If f is NaN, then return f. */
float_bits float_absval(float_bits f) {
    unsigned mask_exp = 0x7F800000;
    unsigned mask_frac = 0x007FFFFF;
    unsigned mask_sign = 0x80000000;
    ;
    if (((f & mask_exp) == mask_exp) && ((f & mask_frac) != 0))
        return f;

    return f & ~mask_sign;
}

float u2f(unsigned x) {
    union {
        unsigned u;
        float f;
    } u;
    u.u = x;
    return u.f;
}

int main(int argc, char const *argv[])
{
    // vector<std::pair<float_bits, float_bits>> testcases {};

    float_bits u = 0x7f800001;
    float_bits res = float_absval(u);
    printf("u2f(u): %f\n", u2f(u));
    float target = fabsf(u2f(u));
    printf("target: %f\n", target);

    if (u2f(res) != target && !(isnan(u2f(res)) && isnan(target))) {
        printf("Test failed. u = %08X. %08X should be %08X.\n", u, res, target);
    }

    printf("Test completed.\n");
    return 0;
}
