#include <iostream>

using namespace std;

int is_little_endian() {
    int x = 1;
    unsigned char* p = (unsigned char*)&x;
    if (p[0] == 1)
        return 1;
    return 0;
}

int main() {
    cout << is_little_endian() << endl;
    return 0;
}