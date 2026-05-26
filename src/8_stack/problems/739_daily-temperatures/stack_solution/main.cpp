#include <vector>
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
        Runtime: 25 ms
        Beats: 41.20%

        Memory: 111.91 MB
        Beats: 7.44%
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int arrSize = static_cast<int>(temperatures.size());
        auto results = vector<int>(arrSize, 0);
        stack<pair<int, int>> processingStack;

        for (int i = 0; i < arrSize; ++i) {
            while (!processingStack.empty() && processingStack.top().first < temperatures[i]) {
                auto [temp, idx] = processingStack.top();
                processingStack.pop();
                results[idx] = i - idx;
            }

            processingStack.emplace(temperatures[i], i);
        }

        return results;
    }
};
