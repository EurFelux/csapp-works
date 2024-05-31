#include <vector>
#include <cstdio>
#include <tuple>

using std::printf;
using std::vector;

/* Declaration of data type where 4 bytes are packed
   into an unsigned */
typedef unsigned packed_t;

/* Extract byte from work.  Return as signed integer */
int xbyte(packed_t word, int bytenum)
{
    // Assume: 0 <= bytenum <= 3
    

}

int main()
{
    vector<std::tuple<int, int, int>> testcases{
        std::make_tuple(0x456789AB, 0, -85),
        std::make_tuple(0x456789AB, 1, -119),
        std::make_tuple(0x456789AB, 2, 0x67),
        std::make_tuple(0x456789AB, 3, 0x45),
    };

    bool pass = true;

    for (int i = 0; i < testcases.size(); ++i)
    {
        packed_t word = std::get<0>(testcases[i]);
        int bytenum = std::get<1>(testcases[i]);
        int target = std::get<2>(testcases[i]);
        int res = xbyte(word, bytenum);
        if (res != target)
        {
            printf("Test %d failed. Expectd %d but got %d. \n", i, target, res);
            pass = false;
        }
    }
    
    if (pass)
    {
        printf("All tests passed.\n");
    }

    return 0;
}