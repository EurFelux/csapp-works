#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>

using std::vector;
using std::printf;
using std::pair;
using std::tuple;

unsigned bit_pattern_A(unsigned k) {
    // mask = 0xFF...FF if k == 0; otherwise mask = 0.
    unsigned mask = (~!!(k ^ 0) + 1);

    // to avoid k == w
    return ~0 << ((k - 1) & mask) << (1 & mask) << (k & ~mask);
}

unsigned bit_pattern_B(unsigned j, unsigned k) {
    unsigned mask_k = (~!!(k ^ 0) + 1);
    unsigned mask_j = (~!!(j ^ 0) + 1); 
    return ~(~0 << ((k - 1) & mask_k) << (1 & mask_k) << (k & ~mask_k))
            << ((j - 1) & mask_j) << (1 & mask_j) << (j & ~mask_j);
}

int main() {
    vector<pair<unsigned, unsigned>> testcases_A {
        {0, ~0},
        {32, 0},
        {4, 0xFFFFFFF0}
    };
    vector<tuple<unsigned, unsigned, unsigned>> testcases_B {
        std::make_tuple(0, 32, ~0),
        std::make_tuple(32, 0, 0),
        std::make_tuple(16, 16, 0xFFFF0000),
        std::make_tuple(0, 16, 0x0000FFFF),
        std::make_tuple(16, 0, 0),
        std::make_tuple(0, 0, 0),
    };

    bool pass = true;

    printf("Test for A:\n");
    for (int i = 0; i < testcases_A.size(); ++i) {
        auto arg = testcases_A[i].first;
        auto res = bit_pattern_A(arg);
        auto target = testcases_A[i].second;
        if (res != target) {
            printf("Test %d failed. Expected %08X but got %08X.\n", i, target, res);
            pass = false;
        }
    }

    printf("Test for B:\n");
    for (int i = 0; i < testcases_B.size(); ++i) {
        auto t = testcases_B[i];
        auto j = std::get<0>(t);
        auto k = std::get<1>(t);
        auto target = std::get<2>(t);
        auto res = bit_pattern_B(j, k);
        if (res != target) {
            printf("Test %d failed. Expected %08X but got %08X.\n", i, target, res);
            pass = false;
        }
    }

    if (pass) {
        printf("All tests passed.\n");
    }

}