# Template for test

## Single

```cpp
#include <vector>
#include <cstdio>

using std::vector;
using std::printf;



int main() {
     vector<int> testcases{
        1, 2, 3
     };

     for (int i = 0; i < testcases.size(); ++i) {
        auto res = function(testcases[i]);
        auto target = 0;
        if (res != target)
            printf("Test %d failed. Expected %d but got %d.\n", i, target, res);
     }

     return 0;
}
```

## Pair

```cpp
#include <vector>
#include <cstdio>
#include <utility>

using std::vector;
using std::printf;

int main() {
     vector<std::pair<, >> testcases{
        
     };

     for (auto o : testcases) {
        auto first = o.first;
        auto second = o.second;
        auto res = function(first, second);
        printf("\n", );
     }

     return 0;
}
```

## Tuple

```cpp
#include <vector>
#include <cstdio>
#include <tuple>

using std::printf;
using std::vector;

int main()
{
    vector<std::tuple<>> testcases{
        std::make_tuple(),
    };

    bool pass = true;

    for (int i = 0; i < testcases.size(); ++i)
    {
        int param_0 = std::get<0>(testcases[i]);
        int param_1 = std::get<1>(testcases[i]);
        int target = std::get<2>(testcases[i]);
        auto res = function(param_0, param_1);

        if (res != target)
        {
            printf("Test %d failed. Expectd %d but got %d. \n", i, target, res);
            pass = false;
        }
    }
    
    if (pass)
    {
        printf("All tests passed.\n");
    }

    return 0;
}
```
