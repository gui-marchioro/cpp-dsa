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
        int topL = 0;
        int leftC = 0;
        int bottomL = matrix.size()-1;
        int rightC = matrix[0].size()-1;
        while (topL <= bottomL || leftC <= rightC) {
            // go to the top right
            for (int c = leftC; c <= rightC; c++) {
                auto element = pair<int, int>{topL, c};
                if (topL > bottomL || leftC > rightC) {
                    return result;
                }
                result.push_back(matrix[topL][c]);
            }
            topL++;
            // go to the bottom right
            for (int l = topL; l <= bottomL; l++) {
                auto element = pair<int, int>{l, rightC};
                if (topL > bottomL || leftC > rightC) {
                    return result;
                }
                result.push_back(matrix[l][rightC]);
            }
            rightC--;
            // go to the bottom left
            for (int c = rightC; c >= leftC; c--) {
                auto element = pair<int, int>{bottomL, c};
                if (topL > bottomL || leftC > rightC) {
                    return result;
                }
                result.push_back(matrix[bottomL][c]);
            }
            bottomL--;
            // go to the top left
            for (int l = bottomL; l >= topL; l--) {
                auto element = pair<int, int>{l, leftC};
                if (topL > bottomL || leftC > rightC) {
                    return result;
                }
                result.push_back(matrix[l][leftC]);
            }
            leftC++;
            //cout << "topL: " << topL << ", bottomL: " << bottomL << ", leftC: " << leftC << ", rightC: " << rightC << endl;
        }
        return result;
    }
};