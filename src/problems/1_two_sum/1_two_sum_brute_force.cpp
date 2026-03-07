#include <vector>
#include <iostream>

using namespace std;
/*  -- Brute force solution
    -- Time complexity: O(n^2)

    -- Leet Code submission results:
        Runtime: 43 ms
        Beats: 25.46%

        Memory: 14.16 MB
        Beats: 66.27%
 */

vector<int> twoSum(vector<int>& nums, int target) {
    auto result = vector<int>();
    for (size_t i = 0; i < nums.size(); ++i)
    {
        // Start j from i+1 to avoid checking the same pair twice
        // and to avoid using the same element twice
        for (size_t j = i+1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target) // Valid pair found
            {
                result.push_back(static_cast<int>(i));
                result.push_back(static_cast<int>(j));
                // Return immediately after finding the first pair that sums up to the target
                // The statement guarantees that there is exactly one solution
                return result;
            }
        }
    }
    return result;
}


int main()
{
    int target = 9;
    auto testVector = vector<int>({2, 7, 11, 15});
    auto result = twoSum(testVector, target);
    for (const auto &i : result)
    {
        std::cout << i << " ";
    }
    return 0;
}
