#include <cstdio>
#include <cmath>

typedef unsigned float_bits;

/* Compute 0.5*f. If f is NaN, then return f. */
float_bits float_half(float_bits f) {
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
    
    if (exp > 1)
        return f & ~mask_exp | ((exp - 1) << 23);
    
    bool to_round = (frac & 0b11) == 0b11;
    frac >>= 1;
    
    if (exp == 1) {
        frac |= (1 << 22);
        if (frac == mask_frac && to_round)
            frac = 0;
        else {
            if (to_round)
                frac += 1;
            f = f & ~mask_exp | ((exp - 1) << 23);
        }
    } else if (exp == 0) {
        if (to_round)
            frac += 1;
    }

    f = f & ~mask_frac | frac;

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

unsigned f2u(float x) {
    union {
        unsigned u;
        float f;
    } u;
    u.f = x;
    return u.u;
}

bool testcase(float_bits u)
{
    float_bits res = float_half(u);
    float target = 0.5 * u2f(u);
    if (u2f(res) != target && !(isnanf(u2f(res)) && isnanf(target))) {
        printf("Test failed. u = %08X. res = %08X and target = %08X.\n", u, res, f2u(target));
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
