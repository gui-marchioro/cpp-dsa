#include <algorithm>
#include <vector>

using namespace std;

/*  -- Sorting + Array handling
    - sort by start times
    - have a result array
    - init it with the first interval
    - iterate remaining intervals checking if the start of next interval < last result interval
    - update resultant interval array in place

    -- Time complexity: O(n)
        - 1 loops

    -- Space complexity: O(n)
        - a resultant vector sized by the input

    -- Leet Code submission results:
        Runtime: 3 ms
        Beats: 89.60%

        Memory: 23.86 MB
        Beats: 58.85%
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; 
        });
        // resultant intervals
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        // iterate intervals and append in results
        for (int i = 1; i < intervals.size(); i++) {
            // check if compared interval is contained inside last result vector timespan
            if (result.back()[1] >= intervals[i][0]){
                // skip inner intervals
                if (result.back()[1] < intervals[i][1]){
                    result.back()[1] = intervals[i][1];
                }
            }
            else {
                // non-overlapping are just appended
                result.emplace_back(vector<int>{intervals[i][0], intervals[i][1]});
            }
        }
        return result;
    }
};