#include <vector>
#include <cstdio>
#include <tuple>
#include <cstring>

using std::printf;
using std::vector;

/* Copy integer into buffer if space is available */
void copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes >= sizeof(val))
        std::memcpy(buf, (void *) &val, sizeof(val));
    else
        printf("Condition test not passed.\n");
}

int main()
{
    vector<int> testcases{
        0, 1, 4
    };

    bool pass = true;

    for (int i = 0; i < testcases.size(); ++i)
    {
        int val = 0x123;
        int buf = 0;
        int* p_buf = &buf;
        copy_int(val, (void *)p_buf, testcases[i]);

        printf("buf: %08X\n", buf);
        
    }
    return 0;
}