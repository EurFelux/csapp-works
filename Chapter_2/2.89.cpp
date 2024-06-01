#include <vector>
#include <cstdio>
#include <tuple>

using std::vector;
using std::printf;


int main() {

    int x = 538923759;
    int y = 123;
    int z = 0;

    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;

    bool res_c = (dx+dy)+dz==dx+(dy+dz);
    bool res_d = (dx*dy)*dz==dx*(dy*dz);
    bool res_e = dx/dx==dz/dz;

    double test_1 = dx/dx;
    double test_2 = dz/dz;
    double test_3 = dy/dy;

    // printf("%lf\n", test_1);
    // printf("%lf\n", test_2);
    // printf("%lf\n", test_3);
    // printf("%d\n", test_1==test_2);
    // printf("%d\n", dx/dx==dz/dz);

    union {
        float f;
        unsigned u;
    } u;
    u.u = 0b11111111100000000000000000000000;
    printf("%f\n", u.f);
    u.u = 0b01111111100000000000000000000000;
    printf("%f\n", u.f);
    printf("%f\n", 1.0/0.0);
    
    return 0;
}