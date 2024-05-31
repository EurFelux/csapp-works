#include <iostream>

int int_size_is_32_B() {
    /* Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 << 31;

    /* Shift past msb of 32-bit word */
    int beyond_msb = 1 << 31 << 1;

    /* set_msb is nonzero when word size >= 32
       beyond_msb is zero when word size <= 32  */
    
    return set_msb && !beyond_msb;
}

int int_size_is_32_C() {
    /* Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 << 15 << 15 << 1;

    /* Shift past msb of 32-bit word */
    int beyond_msb = 1 << 15 << 15 << 2;

    /* set_msb is nonzero when word size >= 32
       beyond_msb is zero when word size <= 32  */
    
    return set_msb && !beyond_msb;
}

int main() {
    std::cout << int_size_is_32_B() << std::endl;
    std::cout << int_size_is_32_C() << std::endl;

    return 0;
}