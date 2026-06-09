#include <string>
#include <vector>

using namespace std;

/*  -- Dynamic Programming
    - The string s should have a path from index 0 towards the end matching words from wordDict
    - Divide and conquer algorithm
    - Start backwards in the s string
    - Try to find a match for each word
    - if a match is found, check if the subsequential index was also a match, if so, it is a valid substring
    - keep the algorithm until index 0

    -- Time complexity: O(n*m*n)
        - 3 nested loops

    -- Space complexity: O(n)
        - vector of valid substring sequence

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 10.27 MB
        Beats: 97.98%
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int textSize = s.size();
        vector<bool> dp(textSize+1, 0); // substring results vector
        dp[textSize] = 1; // end of string is marked valid

        // traverse s backwards
        for (int i = textSize-1; i >= 0; i--) {
            // test it for each word from the dict
            for (auto& word : wordDict) {
                // if the size does not match, just continue
                if (textSize - i < word.size()) {
                    continue;
                }
                bool match = true;
                int j = i;
                // check the sequence substring is a match
                for (char c : word) {
                    // if not just go to the next word
                    if (c != s[j]) {
                        match = false;
                        break;
                    }
                    j++;
                }
                if (!match) {
                    continue;
                }
                // check if the following substring was also a match and save result
                dp[i] = match && dp[i + word.size()];
                // does not check for other words if a match is found
                if (dp[i]) {
                    break;
                }
            }
            
        }

        // after testing all possibilities return result starting from index 0
        return dp[0];
    }
};

int main() {
    Solution sol;
    // string s = "leetcode";
    // auto wordDict = vector<string>{"leet", "code"};
    string s = "cars";
    auto wordDict = vector<string>{"car", "ca", "rs"};
    bool result = sol.wordBreak(s, wordDict);

    return 0;
}
