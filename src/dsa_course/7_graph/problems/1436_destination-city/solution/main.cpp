#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*  -- Set + Array traversal
        - sources set creation
        - Traverse paths again to check for a destination without a source
    -- Time complexity: O(n)
        - all paths are visited twice in the worst case
    -- Space complexity: O(n)
        - a set is created having all source nodes

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 15.04 MB
        Beats: 67.83%
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // sources set creation
        unordered_set<string> sources;
        for (const auto& path : paths) {
            sources.emplace(path[0]);
        }
        // Traverse paths again to check for a destination without a source
        for (const auto& path : paths) {
            if (sources.count(path[1]) == 0) {
                return path[1];
            }
        }

        return "";
    }
};