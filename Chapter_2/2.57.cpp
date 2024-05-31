#include <iostream>
#include <cstdio>
#include <string>

using byte_pointer = unsigned char*;

void show_bytes(byte_pointer start, int len)
{
    for (int i = 0; i < len; ++i)
        std::printf(" %.2x", start[i]);
    std::printf("\n");
}

void show_short(short x) {
    show_bytes((byte_pointer)&x, sizeof(short));
}

void show_long(long x) {
    show_bytes((byte_pointer)&x, sizeof(long));
}

void show_double(double x) {
    show_bytes((byte_pointer)&x, sizeof(double));
}

int main()
{
    short s = 12345;
    long l = 1234567890;
    double d = 1234567890.0;
    show_short(s);
    show_long(l);
    show_double(d);
    return 0;
}