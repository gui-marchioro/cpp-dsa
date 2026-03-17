#include <iostream>
#include <string>

using namespace std;

/*  -- Brute force solution
    The idea here is to check all possible substrings of the input string and determine if they are palindromes.
    We keep track of the longest palindrome found.

    -- Time complexity: O(n^3)
        - 2 nested loops to check all substrings: O(n^2)
        - Checking if a substring is a palindrome: O(n)

    -- Leet Code submission results:
        Runtime: 159 ms
        Beats: 21.83%

        Memory: 23.06 MB
        Beats: 33.64%
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string longest = s.substr(0,1);
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = s.size() - 1; j > i; --j)
            {
                if (isPalindrome(s, i, j))
                {
                    string aux = s.substr(i, j - i + 1);
                    if (aux.size() > longest.size())
                    {
                        longest = aux;
                    }
                    break;
                }
            }
        }
        
        return longest;
    }

    bool isPalindrome(const string &s, int left, int right)
    {
        if (left < 0 || right > s.size())
        {
            // input validation
            return false;
        }

        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};




int main()
{
    Solution solution = Solution();
    string s;
    string response;

    // isPalindrome test
    s = "aaaa";
    bool isPal = solution.isPalindrome(s, 0, 3);
    std::cout << "Is '" << s.substr(0, 4) << "' a palindrome? " << to_string(isPal) << std::endl;
    s = "aaaa";
    isPal = solution.isPalindrome(s, 0, 2);
    std::cout << "Is '" << s.substr(0, 3) << "' a palindrome? " << to_string(isPal) << std::endl;
    s = "aaaa";
    isPal = solution.isPalindrome(s, 0, 1);
    std::cout << "Is '" << s.substr(0, 2) << "' a palindrome? " << to_string(isPal) << std::endl;
    s = "aaaa";
    isPal = solution.isPalindrome(s, 0, 0);
    std::cout << "Is '" << s.substr(0, 1) << "' a palindrome? " << to_string(isPal) << std::endl;
    s = "ccd";
    isPal = solution.isPalindrome(s, 0, 2);
    std::cout << "Is '" << s.substr(0, 3) << "' a palindrome? " << to_string(isPal) << std::endl;
    s = "abc";
    isPal = solution.isPalindrome(s, 0, 2);
    std::cout << "Is '" << s.substr(0, 3) << "' a palindrome? " << to_string(isPal) << std::endl;
    s = "caad";
    isPal = solution.isPalindrome(s, 0, 3);
    std::cout << "Is '" << s.substr(0, 4) << "' a palindrome? " << to_string(isPal) << std::endl;
    s = "caad";
    isPal = solution.isPalindrome(s, 1, 2);
    std::cout << "Is '" << s.substr(1, 2) << "' a palindrome? " << to_string(isPal) << std::endl;
    s = "a";
    isPal = solution.isPalindrome(s, 0, 1);
    std::cout << "Is '" << s.substr(0, 2) << "' a palindrome? " << to_string(isPal) << std::endl;
    s = "a";
    isPal = solution.isPalindrome(s, 0, 0);
    std::cout << "Is '" << s.substr(0, 1) << "' a palindrome? " << to_string(isPal) << std::endl;

    // Test longest string algorithm
    s = "a";
    response = solution.longestPalindrome(s);
    std::cout << "Longest palindrome from '"  << s << "' is '" << response << "'" << std::endl;
    s = "ccc";
    response = solution.longestPalindrome(s);
    std::cout << "Longest palindrome from '"  << s << "' is '" << response << "'" << std::endl;
    s = "cbbd";
    response = solution.longestPalindrome(s);
    std::cout << "Longest palindrome from '"  << s << "' is '" << response << "'" << std::endl;
    s = "abbcccba";
    response = solution.longestPalindrome(s);
    std::cout << "Longest palindrome from '"  << s << "' is '" << response << "'" << std::endl;

    return 0;
}
