#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

/*  -- Monotonic Stack solution
        - create a pre-filled vector
        - use a processing stack and do number comparisons
    -- Time complexity: O(n)
        - concurrent loops, one adds an item, and other withdraw
        - so even though it is an inner loop the overall complexity is n
    -- Space complexity: O(n)
        - stack that in the worst case will carry n elements

    -- Leet Code submission results:
        Runtime: 3 ms
        Beats: 40.98%

        Memory: 12.80 MB
        Beats: 60.31%
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int nums1Size = static_cast<int>(nums1.size());
        vector<int> ans = vector<int>(nums1Size, -1);
        int nums2Size = static_cast<int>(nums2.size());
        stack<int> processingStack;
        unordered_map<int, int> greaterNumMap;
        for (int i = 0; i < nums2Size; i++) {
            int n2 = nums2[i];
            while (!processingStack.empty() && n2 > processingStack.top()) {
                greaterNumMap[processingStack.top()] = n2;
                processingStack.pop();
            }
            processingStack.push(n2);
        }
        for (int i = 0; i < nums1Size; i++) {
            int n1 = nums1[i];
            if (greaterNumMap.count(n1) != 0) {
                ans[i] = greaterNumMap[n1];
            }
        }
        return ans;
    }
};