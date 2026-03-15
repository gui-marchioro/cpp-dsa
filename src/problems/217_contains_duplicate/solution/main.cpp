#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*  -- Array + hash map solution
    The idea here is to:
    - create a hash map to keep track of the items inside the array
    - loop through the array adding new elements to the map
    - if the element is already there, then we found the duplicate

    -- Time complexity: O(n)
        - 1 loop
    -- Space complexity: O(n)
        - In the worst case the duplicate is in the end of the list, and all items are already added to the map

    -- Leet Code submission results:
        Runtime: 54 ms
        Beats: 33.79%

        Memory: 90.83 MB
        Beats: 44.09%
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // hash map to keep track of the items inside the array
        unordered_map<int, int> numberCountMap = {};
        // loop through the array adding new elements to the map
        for (int i = 0; i < nums.size(); ++i)
        {
            int number = nums[i];
            auto itNumber = numberCountMap.find(number);
            if (itNumber == numberCountMap.end())
            {
                numberCountMap[number] = 1;
            }
            else
            {
                // if the element is already there, then we found the duplicate
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    
    vector<int> nums = {1,2,3,1};
    bool result = s.containsDuplicate(nums);
    cout << to_string(result) << endl;
    
    nums = {1,2,3,};
    result = s.containsDuplicate(nums);
    cout << to_string(result) << endl;
}
