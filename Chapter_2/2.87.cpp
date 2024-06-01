#include <cstdio>
#include <vector>

using std::vector;
using std::printf;

int main(int argc, char const *argv[])
{
    vector<_Float16> lst{
        1025./512,
        1023./1024,
        123./128
    };

    for (auto f : lst)
    {
        printf("%f, ", f);
    }

    return 0;
}
