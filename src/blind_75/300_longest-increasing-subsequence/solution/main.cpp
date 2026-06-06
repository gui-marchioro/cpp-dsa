#include <vector>
#include <iostream>

using namespace std;

/*  -- Dynamic Programming
    - Divide and conquer algorithm
    - Start backwards in the nums vector
    - Compute the Longest Increasing Subsequence (LIS) and cache it
    - Use the cached values when computing next index

    -- Time complexity: O(n^2)
        - 2 nested loops

    -- Space complexity: O(n)
        - Cache vector to compute the LIS for each number

    -- Leet Code submission results:
        Runtime: 95 ms
        Beats: 38.29%

        Memory: 14.34 MB
        Beats: 57.87%
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int numsSize = nums.size();
        vector<int> lis(numsSize, 1);
        int nextLis = 1;
        int longest = 1;
        for (int i = numsSize - 1; i >=0; i--) {
            //cout << "cycle: " << numsSize-i << endl;
            if (i >= numsSize - 1) {
                continue;
            }
            for (int j = i+1; j < numsSize; j++) {
                nextLis = lis[j];
                int comparedLis = 1 + nextLis;
                if (nums[i] < nums[j] && lis[i] < comparedLis) {
                    lis[i] = comparedLis;
                    if (lis[i] > longest) {
                        longest = lis[i];
                    }
                }
            }
            //cout << "LIS[" << i << "]: " << lis[i] << endl;
        }
        return longest;
    }
};