#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

/*  -- Optimized solution, using std C++ sorting and two pointers
    -- Time complexity: O(n^2)
        - the inner iterations are O(n^2) (loop inside another loop)
        - here sorting is not limiting the algorithm since it is O(n logn)
    -- Space complexity: O(1) 
        - just 3 pointers are used

    -- Leet Code submission results:
        Runtime: 40 ms
        Beats: 90.63%

        Memory: 28.90 MB
        Beats: 91.86%
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto size = static_cast<int>(nums.size());
        auto result = vector<vector<int>>{};
        if (size < 3)
        {
            // edge case, less than 3 elements in the array
            return result;
        }
        // 1st step sorting
        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
            {
                // edge case, repetitive numbers, to prevent repetitive combinations
                continue;
            }
            int left = i + 1;
            int right = size - 1;
            // 2nd traverse the sorted array
            while (left < right)
            {
                // 3rd inner array iteration to look for 3 sum == 0
                auto sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    // we found a triplet
                    result.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    do
                    {
                        // edge case, repetitive numbers, to prevent repetitive combinations
                        left++;
                    } while (left < right && nums[left] == nums[left - 1]);
                }
                else if (sum > 0)
                {
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
            }
        }

        return result;
    }
};


int main() {
    //auto input = vector<int>{-1,0,1,2,-1,-4};
    //auto input = vector<int>{0,0,0};
    // auto input = vector<int>{0,0,0,0};
    auto input = vector<int>{-100,-70,-60,110,120,130,160};
    Solution sol;
    auto result = sol.threeSum(input);

    for (auto &v: result) {
        cout << "[";
        for (auto i: v) {
            cout << i << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
