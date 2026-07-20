#include <vector>

using namespace std;

/*  
- two pointers sliding window
    - iterate all elements
    - for each element create a sliding window
      - left pointer stays at the element
      - right pointer moves until the end of the array
      - account the sum inner the window
          - if equals to the target k, add 1 to the result

    -- Time complexity: O(n^2)
        - 1 nested loop

    -- Space complexity: O(1)
        - some auxiliar variables created

    -- Leet Code submission results:
        Runtime: 1828 ms
        Beats: 18.67%

        Memory: 34.28 MB
        Beats: 94.33%
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        for (int left = 0; left < nums.size(); left++) {
            int currSum = nums[left];
            if (currSum == k) {
                result++;
            }
            int right = left+1;
            while (right < nums.size()) {
                currSum += nums[right];
                if (currSum == k) {
                    result++;
                }
                right++;
            }
        }
        return result;
    }
};
