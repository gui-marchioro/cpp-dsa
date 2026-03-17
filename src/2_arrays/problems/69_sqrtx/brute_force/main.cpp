#include <iostream>
#include <string>

using namespace std;


/*  -- Brute force solution
    The idea here is to:
    - loop from 0 to x
    - case 1: if the multiplication is equal than x, than that's the square root
    - case 2: if the multiplication is greater than x, than the square root is the number before

    -- Time complexity: O(n)
        - 1 loop

    -- Leet Code submission results:
        Runtime: 23 ms
        Beats: 5.23%

        Memory: 8.46 MB
        Beats: 85.69%
*/


class Solution {
public:
    int mySqrt(int x) {
        // loop from 0 to x
        // case 1: if the multiplication is equal than x, than that's the square root
        // case 2: if the multiplication is greater than x, than the square root is the number before
        int nearestSqrt = 0;
        for (unsigned int i = 0; i <= x; ++i)
        {
            auto aux = static_cast<unsigned long>(i * i);
            if (aux == x)
            {
                nearestSqrt = i;
                return nearestSqrt;
            }
            else if (aux > x)
            {
                nearestSqrt = i - 1;
                return nearestSqrt;
            }
        }
        return nearestSqrt;
    }
};


int main()
{
    Solution solution = Solution();

    int input = 4;
    int response = solution.mySqrt(input);
    cout << "SQRT for input '" << to_string(input) << "' is '" << to_string(response) << "'" << endl;

    input = 8;
    response = solution.mySqrt(input);
    cout << "SQRT for input '" << to_string(input) << "' is '" << to_string(response) << "'" << endl;

    input = 9;
    response = solution.mySqrt(input);
    cout << "SQRT for input '" << to_string(input) << "' is '" << to_string(response) << "'" << endl;
    
    input = 2147483647;
    response = solution.mySqrt(input);
    cout << "SQRT for input '" << to_string(input) << "' is '" << to_string(response) << "'" << endl;
}