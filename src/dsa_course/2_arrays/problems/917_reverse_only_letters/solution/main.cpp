#include <iostream>
#include <string>

using namespace std;

/*  -- Two pointers
    The idea here is to:
    - use two pointers, one in the start and other in the end
    - finish the iterations when they find each other
    - check if the letter can be exchanged directly, if not increase left or decrease right pointer

    -- Time complexity: O(n)
        - 1 loop
    -- Space complexity: O(1)
        - basically two pointers and other aux char vars

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 8.02 MB
        Beats: 55.08%
*/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size();
        // use two pointers, one in the start and other in the end
        // finish the iterations when they find each other
        // check if the letter can be exchanged directly, if not increase left or decrease right pointer
        while (left < right)
        {
            char cLeft = s[left];
            char cRight = s[right];
            if (isAmericanLetter(cLeft) && isAmericanLetter(cRight))
            {
                // Swap
                s[left] = cRight;
                s[right] = cLeft;
                left++;
                right--;
                continue;
            }
            else if (!isAmericanLetter(cLeft))
            {
                left++;
            }
            else if (!isAmericanLetter(cRight))
            {
                right--;
            }
        }
        return s;
    }
private:
    bool isAmericanLetter(char c)
    {
        return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
    }
};


int main()
{
    Solution s = Solution();

    string input = "ab-cd";
    string result = s.reverseOnlyLetters(input);
    cout << result << endl;

    input = "a-bC-dEf-ghIj";
    result = s.reverseOnlyLetters(input);
    cout << result << endl;

    input = "Test1ng-Leet=code-Q!";
    result = s.reverseOnlyLetters(input);
    cout << result << endl;

    return 0;
}
