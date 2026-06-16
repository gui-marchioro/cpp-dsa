#include <vector>

using namespace std;


/*  -- Array traversal, two pointer
    - start -> l = 0, r = 0
    - traverse columns until the end
        [l][c] -> [l][c++] -> [l][n-1] -> 
    - traverse lines until the bottom
        [l++][n-1] -> [m-1][n-1] -> 
    - traverse columns backwards
        [l--][c] -> [m-1][c] -> 
    - traverse lines until the top
        [l++][c] -> [l+1] ->
    - start over
    - break the loop when the pointers limiting the matrix find each other

    -- Time complexity: O(n + m)
        - every element from the matrix will be iterated

    -- Space complexity: O(1)
        - just some auxiliar pointers to traverse the array

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 9.23 MB
        Beats: 80.12%
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top = 0;
        int left = 0;
        int bottom = matrix.size()-1;
        int right = matrix[0].size()-1;
        while (top <= bottom || left <= right) {
            // go to the top right
            for (int c = left; c <= right; c++) {
                auto element = pair<int, int>{top, c};
                result.push_back(matrix[top][c]);
            }
            top++;
            if (top > bottom || left > right) {
                break;
            }
            // go to the bottom right
            for (int l = top; l <= bottom; l++) {
                auto element = pair<int, int>{l, right};
                result.push_back(matrix[l][right]);
            }
            right--;
            if (top > bottom || left > right) {
                break;
            }
            // go to the bottom left
            for (int c = right; c >= left; c--) {
                auto element = pair<int, int>{bottom, c};
                result.push_back(matrix[bottom][c]);
            }
            bottom--;
            if (top > bottom || left > right) {
                break;
            }
            // go to the top left
            for (int l = bottom; l >= top; l--) {
                auto element = pair<int, int>{l, left};
                result.push_back(matrix[l][left]);
            }
            left++;
            //cout << "topL: " << topL << ", bottomL: " << bottomL << ", leftC: " << leftC << ", rightC: " << rightC << endl;
        }
        return result;
    }
};