#include <vector>
#include <cstdio>

using std::printf;
using std::vector;

/* Return 1 when x contains an odd number of 1s; 0 otherwise.
   Assume w=32 */
int odd_ones(unsigned x)
{
   x ^= (x >> 1);
   x ^= (x >> 2);
   x ^= (x >> 4);
   x ^= (x >> 8);
   x ^= (x >> 16);
   return x & 1;
}

int main()
{
   vector<unsigned> testcases{
       0, 0xFE000000, 0x121, 0xFF};

   for (auto o : testcases)
   {
      printf("%08X : %u\n", o, odd_ones(o));
   }

   return 0;
}