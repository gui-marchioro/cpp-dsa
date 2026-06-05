#include <vector>


using namespace std;

/*  -- Binary XOR operation solution
        - uses a property o XOR operation where
            - a number XOR itself cancel out to 0
            - the idea is to XOR every number input
            - then XOR it to every number from 0 to the lenght of the input
            - this will cancel out all repeated numbers 
            - then we will be left with the only missing one
    -- Time complexity: O(n)
        - loop two arrays in sequence
    -- Space complexity: O(1)
        - two int variables needed

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 21.66 MB
        Beats: 93.03%
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto size = static_cast<int>(nums.size());
        int missingNumber = 0;
        for (int i: nums) {
            missingNumber ^= i;
        }
        for (int i = 0; i <= size; i++) {
            missingNumber ^= i;
        }

        return missingNumber;
    }
};


int main() {
    auto sol = Solution{};
    auto input = vector<int>{9,6,4,2,3,5,7,0,1};
    auto missingNumber = sol.missingNumber(input);
    return 0;
}
