#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*  -- max heap solution
        - create hashmap containing all occurrences
        - add elements to a max heap
        - return k elements from max heap
    -- Time complexity:
        - O(n log n) due to max heap operations
    -- Space complexity: O(n)
        - all items are kept in memory

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 17.87 MB
        Beats: 83.91%
*/

class Solution {
public:
    struct Compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        // create hashmap containing all occurrences
        for (auto num : nums) {
            if (map.count(num) == 0) {
                map[num] = 1;
            }
            else {
                map[num]++;
            }
        }
        // add elements to a max heap
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxHeap;
        for (const auto& [num, freq] : map) {
            maxHeap.push({num, freq});
        }
        // return k elements from max heap
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.emplace_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return result;
    }
};