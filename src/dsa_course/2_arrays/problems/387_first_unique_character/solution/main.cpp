#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*  -- Array + map solution
    The idea here is to:
    - loop through the string
    - save single character occurrences on a map with its index
    - add a known flag if already exists, so that it is possible to know it is a duplicate char
    - loop the map and return the first index

    -- Time complexity: O(n)
        - 2 sequential loops
    -- Space complexity: O(n)
        - map of numbers grows linearly as the input grows

    -- Leet Code submission results:
        Runtime: 12 ms
        Beats: 45.07%

        Memory: 14.75 MB
        Beats: 53.94%
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> uniqCharMap = {};
        int uniqCharIdx = -1;

        for (int i = 0; i < s.size(); i++)
        {
            auto c = s[i];
            if (!uniqCharMap.count(c))
            {
                uniqCharMap[c] = i;
            }
            else
            {
                uniqCharMap[c] = -1;
            }
        }

        for (auto it: uniqCharMap)
        {
            if (uniqCharIdx == -1)
            {
                uniqCharIdx = it.second;
            }
            else if (it.second < uniqCharIdx && it.second >= 0)
            {
                uniqCharIdx = it.second;
            }
        }

        return uniqCharIdx;
    }
};

int main() {
    Solution s;
    string input = "leetcode";
    auto result = s.firstUniqChar(input);
    cout << to_string(result) << endl;

    input = "loveleetcode";
    result = s.firstUniqChar(input);
    cout << to_string(result) << endl;

    input = "aabb";
    result = s.firstUniqChar(input);
    cout << to_string(result) << endl;

    input = "aadadaad";
    result = s.firstUniqChar(input);
    cout << to_string(result) << endl;
}
