#include <vector>

using namespace std;

/*  -- Two pointer solution, brute force
        - traverse each number
        - compare it with any other number in the vector
    -- Time complexity: O(n^2)
        - nested loop
    -- Space complexity: O(1)
        - two pointers

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 12.30 MB
        Beats: 91.94%
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int nums1Size = static_cast<int>(nums1.size());
        int nums2Size = static_cast<int>(nums2.size());
        for (int i = 0; i < nums1Size; i++) {
            int n1 = nums1[i];
            ans.emplace_back(-1);
            bool startAnalysis = false;
            for (int j = 0; j < nums2Size; j++) {
                int n2 = nums2[j];
                if (n1 == n2) {
                    startAnalysis = true;
                }
                if (!startAnalysis) {
                    continue;
                }
                if (n1 < n2) {
                    ans[i] = n2;
                    break;
                }
            }
        }
        return ans;
    }
};
