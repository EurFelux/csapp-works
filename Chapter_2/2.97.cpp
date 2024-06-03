#include <cstdio>
#include <cmath>

typedef unsigned float_bits;

/* Create a mask. 0^{w-1-j}1^k0^j from 2.81 */
unsigned create_mask_01k0j(unsigned j, unsigned k) {
    unsigned mask_k = (~!!(k ^ 0) + 1);
    unsigned mask_j = (~!!(j ^ 0) + 1); 
    return ~(~0 << ((k - 1) & mask_k) << (1 & mask_k) << (k & ~mask_k))
            << ((j - 1) & mask_j) << (1 & mask_j) << (j & ~mask_j);
}

/* Compute (float) i. */
float_bits float_i2f(int i) {
    if (!i) return 0;

    // find ui
    
    unsigned sign = i & 0x80000000;

    unsigned ui;
    if (i < 0)
        ui = ~i+1;
    else
        ui = i;
    
    // find k

    unsigned k = 0;
    for (int j = 31; j >= 0; --j) {
        if (ui & create_mask_01k0j(j, 1)) {
            k = j;
            break;
        }
    }

    // find frac and exp

    unsigned frac = (ui & create_mask_01k0j(0, k));
    unsigned exp = k + 127;

    unsigned mask_frac = create_mask_01k0j(0, 23);

    // round
    if (k > 23) {
        unsigned n_tail = k-23;
        unsigned tail = frac & create_mask_01k0j(0, n_tail);
        frac >>= n_tail;
        // if (n_tail > 3)
        //     tail >>= (n_tail - 3);
        // if (n_tail < 3)
        //     tail <<= (3 - n_tail);
        
        bool frac_all_one = (frac & mask_frac) == mask_frac;

        unsigned mask_round = 1 << (n_tail - 1);

        if (tail > mask_round) {
            if (frac_all_one) {
                frac = 0;
                exp += 1;
            } else {
                frac += 1;
            }
        } else if (tail == mask_round && (frac & 1)) {
            if (frac_all_one) {
                frac = 0;
                exp += 1;
            } else {
                frac += 1;
            }
        } else {
            ;
        }
    } else {
        frac <<= (23 - k);
    }

    exp <<= 23;

    return sign | exp | frac;
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
    if (res != f2u(target)) {
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
