#include <vector>
#include <cstdio>
#include <tuple>

using std::vector;
using std::printf;

unsigned f2u(float x)
{
    union
    {
        float f;
        unsigned u;
    } u;

    u.f = x;
    return u.u;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (sx > sy) ||
           (!(sy > sx) &&
            (((ux << 1) <= (uy << 1) && !sx) ||
             ((ux << 1) >= (uy << 1) && sx)));
}

int main() {
    vector<std::tuple<float, float, int>> testcases {
        std::make_tuple(2.3, 3.2, 1),
        std::make_tuple(2.3, 2.3, 1),
        std::make_tuple(2.3, 2.2, 0),
        std::make_tuple(-2.3, 3.2, 1),
        std::make_tuple(-2.3, 2.3, 1),
        std::make_tuple(-3.2, 2.3, 1),
        std::make_tuple(-0.0, 2.3, 1),
        std::make_tuple(2.3, -1.2, 0),
        std::make_tuple(2.3, -3.2, 0),
        std::make_tuple(2.3, -0.0, 0),
        std::make_tuple(-2.3, -1.2, 1),
        std::make_tuple(-2.3, -3.2, 0),
    };

    for (size_t i = 0; i < testcases.size(); ++i) {
        auto t = testcases[i];
        float x = std::get<0>(t);
        float y = std::get<1>(t);
        int target = std::get<2>(t);
        int res = float_le(x, y);
        
        if (res != target) {
            printf("Test %d failed. Expected %d but got %d.\n", i, target, res);
        }
    }
    return 0;
}