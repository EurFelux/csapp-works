#include <cstdio>
#include <cmath>

typedef unsigned float_bits;

/* Compute (int) f.
 * If conversion causes overflow of f is NaN, return 0x80000000
 */
int float_f2i(float_bits f) {
    unsigned mask_exp = 0x7F800000;
    unsigned mask_frac = 0x007FFFFF;
    unsigned mask_sign = 0x80000000;

    float_bits exp = (f & mask_exp) >> 23;
    float_bits frac = f & mask_frac;

    // nan or inf
    bool is_special = (f & mask_exp) == mask_exp;
    bool is_overflow = (exp > 158) || ((exp == 158) && !((f & mask_sign) && !(frac)));
    if (is_special || is_overflow)
        return 0x80000000;

    // handle 0
    if (exp < 127)
        return 0;

    if (f == 0xCF000000)
        return INT_MIN;

    unsigned E = exp - 127;
    unsigned d = E < 23 ? E : 23;
    unsigned I = (frac | (1 << 23)) >> (23 - d);

    bool is_neg = !!(f & mask_sign);
    if (is_neg)
        return -1 * (int)(I << (E - d));
    else
        return (int)(I << (E - d));
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
    int res = float_f2i(u);
    int target = (int)u2f(u);
    if (res != target) {
        printf("Test failed. u = %08X. res = %d and target = %d.\n", u, res, target);
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    printf("Testing for 2.96 ...\n");
    for (float_bits u = 0; u < __UINT32_MAX__; ++u) {
        if (!testcase(u)) break;
    }
    testcase(__UINT32_MAX__);

    printf("Test completed.\n");
    return 0;
}
