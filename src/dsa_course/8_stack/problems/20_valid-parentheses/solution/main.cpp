#include <string>
#include <deque>

using namespace std;

/*  -- Stack based solution
        - for each opening bracket, we add to a queue an expected closure
        - for each closing bracket we compare it to the first element in the stack
        - if not expected, return false

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 10.02 MB
        Beats: 5.53%
*/

class Solution {
public:
    bool isValid(string s) {
        deque<char> enclosings;
        for (char c : s) {
            if (c == '(') {
                enclosings.push_back(')');
            }
            else if (c == '[') {
                enclosings.push_back(']');
            }
            else if (c == '{') {
                enclosings.push_back('}');
            }
            else {
                if (enclosings.empty()) {
                    // if a closure is found and not expected
                    return false;
                }
                char popped = enclosings.back();
                enclosings.pop_back();
                if (c != popped) {
                    return false;
                }
            }
        }

        if (!enclosings.empty()) {
            // if closures are missing
            return false;
        }

        return true;
    }
};