#include <iostream>
#include <string>

using namespace std;


/*  -- Binary search solution
    The idea here is to:
    - use binary search to find the square root of x
    - we will have 3 pointers: l, i and r
    - l will be the left pointer, i will be the middle pointer and r will be the right pointer
    - we will loop until we find the square root of x or until l is greater than r
    - case 1: if the multiplication is equal than x, than that's the square root
    - case 2: if the multiplication is greater than x,
                 test if the multiplication of the number before is less than or equal to x, than that's the square root,
                 if not, move the right pointer to i and calculate the new middle pointer
    - case 3: if the multiplication is less than x,
                 test if the multiplication of the number after is greater than x, than the number before is nearest square root,
                 if not, move the left pointer to i and calculate the new middle pointer

    -- Time complexity: O(log n)
        - 1 loop

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.0%

        Memory: 8.54 MB
        Beats: 50.03%
*/


class Solution {
public:
    int mySqrt(int x) {
        unsigned int l = 0;
        unsigned int i = x / 2;
        unsigned int r = x;
        int nearestSqrt = 0;
        while (l <= r)
        {
            unsigned long aux = static_cast<unsigned long>(i) * i;
            if (aux == x)
            {
                nearestSqrt = i;
                return nearestSqrt;
            }
            else if (aux > x)
            {
                aux = static_cast<unsigned long>(i-1) * (i-1);
                if (aux <= x)
                {
                    nearestSqrt = i-1;
                    return nearestSqrt;
                }
                r = i;
                i = (r - l) / 2;
            }
            else if (aux <= x)
            {
                aux = static_cast<unsigned long>(i+1) * (i+1);
                if (aux > x)
                {
                    nearestSqrt = i;
                    return nearestSqrt;
                }
                l = i + 1;
                i = l + ((r - l) / 2);
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