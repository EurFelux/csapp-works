#include <vector>
#include <cstdio>
#include <climits>
#include "utils.h"

using std::vector;
using std::printf;

int generate(int x)
{
    unsigned mask = 0xff << ((sizeof(int) - 1) << 3);
    return !(x ^ ~0) ||
           !(x ^ 0) ||
           !((x & 0xff) ^ 0xff) ||
           !((x & mask) ^ 0);
}

int main()
{
    vector<int> lst{
        INT_MIN,    // 0
        -1,         // 1
        0,          // 1
        0xff,       // 1
        1,          // 1
        1 << 28,    // 0
        (1 << 28) + 0xff,   // 1
    };

    for (int i : lst)
    {
        printf("%12d : %d\n", i, generate(i));
    }

    return 0;
}