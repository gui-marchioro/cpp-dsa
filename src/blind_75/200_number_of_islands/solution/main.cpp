#include <queue>
#include <vector>

using namespace std;

/*  -- Graph BFS traversal to find all connected nodes
        - given a matrix of connected nodes
        - count all unconnected graphs
    -- Time complexity: O(m * n * (V + E))
    -- Space complexity: O(V + E)
        - All edges and vertices are stored in the visited set

    -- Leet Code submission results:
        Runtime: 24 ms
        Beats: 77.64%

        Memory: 18.82 MB
        Beats: 36.45%
*/


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // visit all tiles
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0' || visited[i][j]) {
                    // skip water and already visited
                    continue;
                }
                // we are on an island now
                //cout << "i: " << i << ", j: " << j << endl;
                numIslands++;
                visited[i][j] = true;
                q.push({i,j});
                // bfs
                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    // visit all surrounding tiles horizontally and vertically
                    if (x < m-1 && grid[x+1][y] == '1' && !visited[x+1][y]) {
                        q.push({x+1,y});
                        visited[x+1][y] = true;
                    }
                    if (y < n-1 && grid[x][y+1] == '1' && !visited[x][y+1]) {
                        q.push({x,y+1});
                        visited[x][y+1] = true;
                    }
                    if (x > 0 && grid[x-1][y] == '1' && !visited[x-1][y]) {
                        q.push({x-1,y});
                        visited[x-1][y] = true;
                    }
                    if (y > 0 && grid[x][y-1] == '1' && !visited[x][y-1]) {
                        q.push({x,y-1});
                        visited[x][y-1] = true;
                    }
                }
            }
        }
        return numIslands;
    }
};