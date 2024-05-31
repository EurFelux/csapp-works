#include <vector>
#include <cstdio>
#include <tuple>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <cstring>

using std::printf;
using std::vector;

int mul_ok(size_t x, size_t y) {
    size_t p = x * y;
    return !x || p/x == y;
}

void *calloc(size_t nmemb, size_t size) {
    if (!mul_ok(nmemb, size) || !nmemb || !size)
        return NULL;
    
    void* p = malloc(nmemb * size);
    memset(p, 0, nmemb * size);

    return p;
}

int main()
{
    int* p = (int*)calloc(0, 4);
    if (p)
        printf("Test 1 failed.\n");
    else
        free(p);
    


    p = (int*)calloc(4, 0);
    if (p)
        printf("Test 2 failed.\n");
    else
        free(p);



    p = (int*)calloc(4, 4);
    if (!p)
        printf("Test 3 failed.\n");
    else {
        for (int i = 0; i < 4; ++i)
            printf("%08X ", p[i]);
        printf("\n");
        free(p);
    }

    return 0;
}