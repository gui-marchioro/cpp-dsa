#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*  -- Sliding window + hash map solution
    The idea here is to:
    - create a window k sized clamped at nums.size()
    - create a hash map to keep track of the items in the window
    - Initialize map to keep track of window items and evaluate early if a duplicate was found
    - Then loop through the rest of the array, updating the window (adding new items and removing old ones) and evaluating if a duplicate was found

    -- Time complexity: O(n)
        - 2 sequential loops, one for initialization and one for window update

    -- Leet Code submission results:
        Runtime: 83 ms
        Beats: 28.78%

        Memory: 98.66 MB
        Beats: 49.48%
*/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2)
        {
            // edge case, no duplicates can be found
            return false;
        }

        // create a window k sized clamped at nums.size()
        int l = 0;
        int r = k < nums.size() ? k : nums.size() - 1;
        unordered_map<int, int> windowItems = {};

        // Initialize map to keep track of window items
        for (int i = l; i < r; ++i)
        {
            int itNumber = nums[i];
            const auto it = windowItems.find(itNumber);
            if (it != windowItems.end())
            {
                windowItems[itNumber] += 1;
            }
            else
            {
                windowItems[itNumber] = 1;
            }

            // Evaluate duplicate was ffound
            if (windowItems[itNumber] == 2)
            {
                return true;
            }
        }

        // window update loop
        while (r < nums.size())
        {
            int itNumber = nums[r];
            const auto it = windowItems.find(itNumber);
            if (it != windowItems.end())
            {
                windowItems[itNumber] += 1;
            }
            else
            {
                windowItems[itNumber] = 1;
            }

            // Evaluate duplicate was ffound
            if (windowItems[itNumber] == 2)
            {
                return true;
            }

            int withdrawNumber = nums[l];
            windowItems[withdrawNumber] -= 1;
            r++;
            l++;
        }
        // nothing was found
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,2,3,1};
    int k = 3;
    cout << s.containsNearbyDuplicate(nums, k) << endl;
    
    nums = {1,2,3,1,2,3};
    k = 2;
    cout << s.containsNearbyDuplicate(nums, k) << endl;
    
    nums = {1};
    k = 1;
    cout << s.containsNearbyDuplicate(nums, k) << endl;
    
    nums = {1,2};
    k = 2;
    cout << s.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}
