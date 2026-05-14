#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

/*  -- Graph DFS traversal in search for cycles
        - given a root node
        - iterate each node labeling them as [unvisited, visiting, visited]
        - if a node is found again in the "visiting" state during the search, we are dealing with a cyclic graph
    -- Time complexity: O(V + E)
        - We traverse all the edges and vertices
    -- Space complexity: O(V + E)
        - All edges and vertices are stored in the graph adjacency list

    -- Leet Code submission results:
        Runtime: 2 ms
        Beats: 79.22%

        Memory: 19.40 MB
        Beats: 53.32%
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // graph creation
        vector<vector<int>> graph(numCourses);
        for (const auto& coursePrereq : prerequisites) {
            graph[coursePrereq[0]].push_back(coursePrereq[1]);
        }
        // DFS to search for possible cycles
        vector<int> state(numCourses, 0);
        // possible states
        // 0 = unvisited
        // 1 = visiting
        // 2 = visited
        for (int i = 0; i < numCourses; ++i) {
            bool hasCycle = !isAcyclicDfs(i, graph, state);
            if (hasCycle) {
                // If cycle found, return false
                return false;
            }
        }
        
        // If no cycle is found, return true
        return true;
    }
private:
    bool isAcyclicDfs(int node, const vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] == 1) {
            return false;
        }
        if (state[node] == 2) {
            return true;
        }

        state[node] = 1;

        for (const int pre: graph[node]) {
            if (!isAcyclicDfs(pre, graph, state)) {
                return false;
            }
        }

        state[node] = 2;
        return true;
    }
};

int main() {
    Solution sol;
    /* int numCourses = 2;
    vector<vector<int>> prerequisites{
        {0, 1}, {1, 0}
    }; */
    // [[2,0],[1,0],[3,1],[3,2],[1,3]]
    int numCourses = 4;
    vector<vector<int>> prerequisites{
        {2, 0}, {1, 0}, {3, 1}, {3, 2}, {1, 3}
    };
    bool result = sol.canFinish(numCourses, prerequisites);
    return 0;
}
