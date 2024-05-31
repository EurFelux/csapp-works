#include <iostream>
#include <climits>
#include "utils.h"

using namespace std;

int int_shifts_are_arithmetic()
{
    int x = INT_MIN;
    return (x >> ((sizeof(int) << 3) - 1)) == -1;
}

int main()
{
    cout << int_shifts_are_arithmetic();
    return 0;
}