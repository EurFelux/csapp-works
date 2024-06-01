#include <cstdio>
#include <cmath>

typedef unsigned float_bits;

/* Compute 2*f.  If f is NaN, then return f. */
float_bits float_twice(float_bits f) {
    unsigned mask_exp = 0x7F800000;
    unsigned mask_frac = 0x007FFFFF;
    unsigned mask_sign = 0x80000000;

    // nan or inf
    bool is_special = (f & mask_exp) == mask_exp;
    bool is_zero = !(f & ~mask_sign);
    if (is_special || is_zero)
        return f;

    float_bits exp = (f & mask_exp) >> 23;
    float_bits frac = f & mask_frac;
    
    // return inf
    if (exp == 0xfe)
        return (f & mask_sign) ? (mask_exp | mask_sign) : mask_exp;
    
    // normal
    if (exp > 0)
        return f & ~mask_exp | ((exp + 1) << 23);
    
    // handle exp = 0
    unsigned mask_frac_highest = 0x00400000;
    if (frac & mask_frac_highest) {
        exp += 1;
        frac <<= 1;
        frac &= mask_frac;
    } else {
        frac <<= 1;
    }
    

    f = f & ~mask_frac | frac;
    f = f & ~mask_exp | (exp << 23);

    return f;
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
    float_bits res = float_twice(u);
    float target = 2 * u2f(u);
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
