#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*  -- Array + set solution
    The idea here is to:
    - save numbers from nums1 in a set
    - loop nums2 and find the intersection numbers
        - adding it to the result if not present yet
        - removing the added numbers from the set to prevent duplicates

    -- Time complexity: O(n)
        - 2 sequential loops
    -- Space complexity: O(n)
        - Set of numbers grows linearly as the input grows

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.0%

        Memory: 14.07 MB
        Beats: 69.48%
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numSet = {};
        vector<int> result = {};
        // save numbers from nums1 in a set
        // loop nums2 and find the intersection numbers adding it to the result if not present yet

        for (int i = 0; i < nums1.size(); i++)
        {
            numSet.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            int number = nums2[i];
            if (numSet.count(number))
            {
                result.push_back(number);
                // remove the item so that it won't be added again
                numSet.erase(number);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    auto result = s.intersection(nums1, nums2);
    for (auto i: result)
    {
        cout << to_string(i) << ", ";
    }
    cout << endl;
    
    nums1 = {4,9,5};
    nums2 = {9,4,9,8,4};
    result = s.intersection(nums1, nums2);
    for (auto i: result)
    {
        cout << to_string(i) << ", ";
    }
    cout << endl;
}
