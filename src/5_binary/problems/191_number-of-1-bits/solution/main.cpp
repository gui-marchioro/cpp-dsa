#include <iostream>

/*  -- Binary Bitwise solution
        - given number is compared against 1 to see if has last bit set
        - if last bit is 1, count ++
        - given number is right shifted
        - cycle repeats until the number is zeroed
    -- Time complexity: O(log(n))
        - depending on the size input log(n) steps will result
    -- Space complexity: O(1)
        - one int var

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 8.18 MB
        Beats: 80.95%
*/

class Solution {
public:
    int hammingWeight(int n) {
        int bitSetCount = 0;
        while (n > 0) {
            bitSetCount += n & 1;
            n = n >> 1;
        }

        return bitSetCount;
    }
};


int main() {
    Solution solution;
    int n = 11; // Example input
    int result = solution.hammingWeight(n);
    std::cout << "Number of 1 bits in " << n << " is: " << result << std::endl;
    return 0;
}
