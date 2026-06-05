#include <algorithm>
#include <functional>
#include <iostream>
#include <string_view>
#include <vector>


int main()
{
    auto vec = std::vector<int>{3, 4, 2, 5, 7};
    // auxiliar lambda for printing the vector
    auto print = [&vec](std::string_view const rem)
    {
        for (auto a : vec)
            std::cout << a << ' ';
        std::cout << ": " << rem << '\n';
    };

    std::sort(vec.begin(), vec.end());
    print("sorted with the default operator<");

    std::sort(vec.begin(), vec.end(), std::greater<int>());
    print("sorted with the standard library compare function object");

    std::sort(vec.begin(), vec.end(), [](int a, int b)
                                  {
                                      return a > b;
                                  });
    print("sorted with a lambda expression");
    return 0;
}
