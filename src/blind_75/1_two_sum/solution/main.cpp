#include <unordered_map>
#include <vector>

using namespace std;

/*  -- Hash map + Array handling
    - fill a map with numbers contained in nums vector and their indexes
    - if a partner is found, just return their indexes

    -- Time complexity: O(n)
        - 1 loop

    -- Space complexity: O(1)
        - a resultant vector with fixed size (2)

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 14.84 MB
        Beats: 37.13%
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int partner = target - nums[i];
            if (numsMap.count(partner) == 0) {
                numsMap[nums[i]] = i;
            }
            else {
                result.push_back(numsMap[partner]);
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
};