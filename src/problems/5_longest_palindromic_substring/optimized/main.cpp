#include <iostream>
#include <string>

using namespace std;

/*  -- Optimized solution
    The idea here is to center a pointer on each character from the string
    checking for odd or even palindromes by growing a substring around the char iterated

    Based at: https://www.youtube.com/watch?v=XYQecbcd6_c

    -- Time complexity: O(n^2)
        - 1 loop to check each character: O(n)
        - 2 sequencial while loops to check for odd and even palindromes: O(n) in the worst case (when the string is a palindrome itself)

    -- Leet Code submission results:
        Runtime: 13 ms
        Beats: 54.87%

        Memory: 22.23 MB
        Beats: 33.98%
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string longest = s.substr(0,1);
        int longestSize = 0;
        string aux;
        int auxSize = 0;

        int strSize = s.size();
        for (int i = 0; i < strSize; i++)
        {
            // odd check
            int l = i;
            int r = i;
            while (l >= 0 && r < strSize && s[l] == s[r])
            {
                auxSize = r - l + 1;
                if (auxSize > longestSize)
                {
                    longestSize = auxSize;
                    longest = s.substr(l, auxSize);
                }
                l--;
                r++;
            }
            // even check
            l = i;
            r = i + 1;
            while (l >= 0 && r < strSize && s[l] == s[r])
            {
                auxSize = r - l + 1;
                if (auxSize > longestSize)
                {
                    longestSize = auxSize;
                    longest = s.substr(l, auxSize);
                }
                l--;
                r++;
            }
        }
        
        return longest;
    }
};




int main()
{
    Solution solution = Solution();
    string s;
    string response;

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
