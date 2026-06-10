#include <unordered_map>
#include <string>

using namespace std;

/*  -- Hash map solution
    - iterate s and parse into a hashmap
        - char as keys, freq as value
    - iterate t
        - check if contained in the map, reduce the count or remove element
        - if not return false
    - in the end, check if the map is empty, if so, return true

    -- Time complexity: O(n + m)
        - 2 sequential loops

    -- Space complexity: O(n)
        - a map containing n elements

    -- Leet Code submission results:
        Runtime: 4 ms
        Beats: 34.32%

        Memory: 10.00 MB
        Beats: 10.91%
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for (const char c : s) {
            if (map.count(c) == 0) {
                map[c] = 1;
            }
            else {
                map[c]++;
            }
        }
        for (const char c : t) {
            if (map.count(c) == 0) {
                return false;
            }
            else {
                map[c]--;
                if (map[c] == 0) {
                    map.erase(c);
                }
            }
        }
        if (map.size() == 0){
            return true;
        }
        else {
            return false;
        }
    }
};