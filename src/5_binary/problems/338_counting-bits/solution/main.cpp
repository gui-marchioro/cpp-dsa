#include <iostream>
#include <vector>

using namespace std;

/*  -- Binary Bitwise solution + loop
        - a loop of numbers until n used
        - given number is compared against 1 to see if has last bit set
        - if last bit is 1, count ++
        - given number is right shifted
        - cycle repeats until the number is zeroed
    -- Time complexity: O(n log(n))
        - a loop of n steps
        - an inner loop of logn steps
    -- Space complexity: O(n)
        - a vector having n results

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 11.23 MB
        Beats: 29.92%
*/

class Solution {
public:
    int countBitsFromNumber(int n) {
        int bitCount = 0;
        while (n > 0) {
            bitCount += n & 1;
            n = n >> 1;
        }

        return bitCount;
    }

    vector<int> countBits(int n) {
        auto result = vector<int>{};
        for (int i = 0; i <= n; i++) {
            result.push_back(countBitsFromNumber(i));
        }
        return result;
    }
};


int main() {
    Solution solution;
    int input = 5;
    auto result = solution.countBits(input);
    
    return 0;
}
