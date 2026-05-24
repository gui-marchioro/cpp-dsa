#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

/*  -- Graph BFS traversal to find all connected nodes
        - given a matrix of connected nodes
        - count all unconnected graphs
    -- Time complexity: O(m * n * (V + E))
    -- Space complexity: O(V + E)
        - All edges and vertices are stored in the visited set

    -- Leet Code submission results:
        Runtime: 130 ms
        Beats: 5.00%

        Memory: 33.13 MB
        Beats: 5.01%
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // m == grid.length
        // n == grid[i].length
        // 1 <= m, n <= 300
        int m = grid.size();
        int n = grid[0].size();
        // starting point
        int numIslands = 0;
        vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        unordered_set<string> visited;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited.find(to_string(i) + "," + to_string(j)) != visited.end()) {
                    // skip water and already visited fields
                    continue;
                }
                // we got a piece of land
                numIslands += 1;
                // bfs to traverse entire land field
                queue<pair<int, int>> q;
                visited.insert(to_string(i) + "," + to_string(j));
                q.emplace(i, j);
                while (!q.empty()) {
                    auto [nodeRow, nodeCol] = q.front();
                    q.pop();

                    for (auto& dir : directions) {
                        int row = nodeRow + dir.first;
                        int col = nodeCol + dir.second;
                        if (row >= 0 && row < m && col >= 0 && col < n
                             && grid[row][col] == '1' && visited.find(to_string(row) + "," + to_string(col)) == visited.end()) {
                            q.emplace(row, col);
                            visited.insert(to_string(row) + "," + to_string(col));
                        }
                    }
                }
                
            }
        }

        return numIslands;
    }
};
