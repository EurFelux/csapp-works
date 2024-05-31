#include <vector>
#include <tuple>
#include <cstdio>

using std::vector;
using std::printf;

using srl_testcase = std::tuple<unsigned, int, unsigned>;
using sra_testcase = std::tuple<int, int, int>;


unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;

    /* My code */
    
    // create mask

    const unsigned w = 8*sizeof(int);

    // if k == 0, then mask_k == 0 because overflow occurs; otherwise mask_k == 0xFF...FF
    unsigned mask_k = (~(!!k) + 1);

    // Here, if k == 0, ((w - k) & mask_k) would be 0, so left shift 0 bit; otherwise left shift w-k bits.
    // Then do exclusive or. No matter k == 0 or not, the result is correct.
    unsigned mask = (~0 << ((w - k) & mask_k)) ^ mask_k;

    return xsra & mask;
}

int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;

    /* My code */
    const unsigned w = 8*sizeof(int);

    // if k == 0, then mask == 0 because overflow occurs; otherwise mask == 0xFF...FF.
    unsigned mask_k = (~(!!k) + 1);

    // if x < 0, then mask_flag == ~0; otherwise mask_flag == 0.
    unsigned mask_flag = ~(!!(x & (1 << (w-1)))) + 1;

    unsigned mask = (~0 << ((w - k) & mask_k) ^ (~0 & ~mask_k)) & mask_flag;
    
    return xsrl | mask;
    
}

int main() {
    vector<srl_testcase> srl_testcases{
        std::make_tuple(0xFFFFFFFF, 0, 0xFFFFFFFF),
        std::make_tuple(0xFFFFFFFF, 31, 1),
        std::make_tuple(0xFFFFFFFF, 16, 0x0000FFFF),
    };
    vector<sra_testcase> sra_testcases{
        std::make_tuple(-0x123456, 0, -0x123456),
        std::make_tuple(-0x123456, 31, 0xFFFFFFFF),
        std::make_tuple(-0x123456, 16, 0xFFFFFFED),
        std::make_tuple(0x123456, 0, 0x123456),
        std::make_tuple(0x123456, 16, 0x00000012),
    };

    printf("srl test:\n");
    for (auto t : srl_testcases) {
        printf("origin: %08X, result: %08X, target: %08X\n", std::get<0>(t), srl(std::get<0>(t), std::get<1>(t)), std::get<2>(t));
    }

    printf("sra test:\n");
    for (auto t : sra_testcases) {
        printf("origin: %08X, result: %08X, target: %08X\n", std::get<0>(t), sra(std::get<0>(t), std::get<1>(t)), std::get<2>(t));
    }
}