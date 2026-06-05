#include <iostream>
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
        Runtime: Time Limit Exceded
        Beats: -

        Memory: -
        Beats: -
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        for (int i = 0; i < temperatures.size() - 1; ++i) {
            int next = i + 1;
            int currectTemp = temperatures[i];
            //cout << "iteration: " << i << endl;
            //cout << "currentTemp: " << currectTemp << endl;
            while (next < temperatures.size() && temperatures[next] <= currectTemp) {
                //cout << "nextTemp: " << temperatures[next] << endl;
                ++next;
            }
            if (next == temperatures.size()) {
                //cout << "no warmer found, 0 added" << endl;
                result.emplace_back(0);
            }
            else {
                //cout << "warmer found, adding: " << (next - i) << endl;
                result.emplace_back(next - i);
            }
        }

        result.emplace_back(0);
        return result;
    }
};