#include <cstdio>
#include <cmath>

typedef unsigned float_bits;

/* Compute (float) i. */
float_bits float_i2f(int i) {
        
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

bool testcase(int i)
{
    float_bits res = float_i2f(i);
    float target = (float) i;
    if (res != target) {
        printf("Test failed. i = %d. res = %08X and target = %08X.\n", i, res, f2u(target));
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    printf("Testing for 2.97 ...\n");
    for (float_bits u = 0; u < __UINT32_MAX__; ++u) {
        if (!testcase(u)) break;
    }
    testcase(__UINT32_MAX__);

    printf("Test completed.\n");
    return 0;
}
