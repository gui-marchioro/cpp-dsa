#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
/*  -- Half optimized solution, using sorting and two pointers
    -- Time complexity: O(nlog(n)) 
        - limited by the sort operation, which is O(nlog n)
        - there are also "n" iterations to fill up a copy input array
    -- Space complexity: O(n) 
        - a vector of size "n" is filled with values and index info

    -- Leet Code submission results:
        Runtime: 4 ms
        Beats: 52.26%

        Memory: 14.67 MB
        Beats: 62.33%
*/

vector<int> twoSum(vector<int>& nums, int target) {
    // 1st step: Store vector input along its original index
    auto len = nums.size();
    vector<pair<int, int>> numsCopy;
    for (int i = 0; i < len; i++) {
        numsCopy.push_back({nums[i], i});
    }
    // 2nd step: Sorting
    sort(numsCopy.begin(), numsCopy.end());
    // 3rd step: Two pointers
    int l = 0;
    int r = static_cast<int>(len - 1);
    while (l < r)
    {
        auto sum = numsCopy[l].first + numsCopy[r].first;
        if (sum < target)
        {
            l++;
        }
        else if (sum > target)
        {
            r--;
        }
        else if (sum == target)
        {
            return vector<int>{numsCopy[l].second, numsCopy[r].second};
        }
    }
    return vector<int>{};
}

int main()
{
    int target = 6;
    auto testVector = vector<int>({3, 2, 4});
    auto result = twoSum(testVector, target);
    for (const auto &i : result)
    {
        std::cout << i << " ";
    }
    return 0;
}
