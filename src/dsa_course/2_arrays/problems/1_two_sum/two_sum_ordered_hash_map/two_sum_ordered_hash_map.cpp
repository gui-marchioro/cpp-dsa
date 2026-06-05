#include <map>
#include <vector>
#include <iostream>

using namespace std;
/*  -- Half optimized solution
    -- Time complexity: O(nlog(n)) due to the map operations, which are O(log n) on average

    -- Leet Code submission results:
        Runtime: 2 ms
        Beats: 73.02%

        Memory: 14.78 MB
        Beats: 52.06%
*/

vector<int> twoSum(vector<int>& nums, int target) {
    auto result = vector<int>();
    auto sumMap = map<int, int>();
    for (size_t i = 0; i < nums.size(); ++i)
    {
        // If the number is present in the map, the sum was found
        if (sumMap.count(nums[i]))
        {
            result.push_back(static_cast<int>(i));
            result.push_back(sumMap.at(nums[i]));
            // Return immediately after finding the first pair that sums up to the target
            // The statement guarantees that there is exactly one solution
            return result;
        }
        // Store the current number's complement in the map as a key
        // Store the index as a value
        sumMap[target - nums[i]] = static_cast<int>(i);
    }
    return result;
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
