#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

/*  -- Graph Dijkstra's algorithm
        - create graph array (adjency list format)
        - Dijkstra to find shortest distances
        - return the greater shortest distance or -1 if unreacheable
    -- Time complexity: O((V + E) log V)
        - from Djikstra algorithm
    -- Space complexity: O((V + E))
        - from Djikstra algorithm

    -- Leet Code submission results:
        Runtime: 86 ms
        Beats: 48.15%

        Memory: 44.36 MB
        Beats: 67.61%
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create graph array
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& time : times) {
            int source = time[0]-1;
            int dest = time[1]-1;
            int weight = time[2];
            graph[source].emplace_back(dest, weight);
        }

        // dijkstra to calculate shortest distances
        // Distance array
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;

        // Min Heap: {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        minHeap.emplace(0, k-1);

        while (!minHeap.empty()) {
            int currentDist = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            // Skip outdated entries
            if (currentDist > dist[node]) {
                continue;
            }

            // Explore neighbors
            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                int newDist = currentDist + weight;

                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    minHeap.emplace(newDist, nextNode);
                }
            }
        }

        // return the greater shortest distance
        int answer = *max_element(dist.begin(), dist.end());
        return answer == INT_MAX ? -1 : answer;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> times;
    times.push_back({2,1,1});
    times.push_back({2,3,1});
    times.push_back({3,4,1});
    int n = 4;
    int k = 2;
    int result = sol.networkDelayTime(times, n, k);

    return 0;
}
