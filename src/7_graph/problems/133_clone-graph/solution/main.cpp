#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

/*  -- Graph BFS traversal
        - given a root node
        - add neighbors to queue
        - get their val info
        - have a hashmap containing val as a key and Node instance
        - avoid to repeat looking for nodes already in the hashmap
    -- Time complexity: O(n)
        - all TreeNodes are visited at least once
    -- Space complexity: average O(log n), worst O(n)
        - In a completely unbalanced tree all nodes would be kept in memory

    -- Leet Code submission results:
        Runtime: 7 ms
        Beats: 22.43%

        Memory: 11.89 MB
        Beats: 90.16%
*/

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        // add neighbors to queue
        // get their val info
        // have a hashmap containing val as a key and Node instance
        if (!node) {
            return node;
        }
        auto clones = unordered_map<int, Node*>{};
        auto nodesToProcess = queue<Node*>{};
        auto firstNode = new Node{node->val};
        clones.emplace(firstNode->val, firstNode);
        nodesToProcess.push(node);
        while (!nodesToProcess.empty())
        {
            auto currNode = nodesToProcess.front();
            nodesToProcess.pop();
            for (int i = 0; i < currNode->neighbors.size(); i++) {
                // traverse node neighbors
                auto neighbor = currNode->neighbors[i];
                if (clones.count(neighbor->val) == 0) {
                    // add unseen nodes to the map
                    Node* newNode = new Node{neighbor->val};
                    clones[neighbor->val] = newNode;
                    // add unseen nodes to the processQueue
                    nodesToProcess.push(neighbor);
                }
                // add a reference to the copied nodes of its neighbor
                auto clone = clones[currNode->val];
                clone->neighbors.push_back(clones[neighbor->val]);
            }
        }
        return firstNode;
    }
};


int main() {
    Solution sol;
    auto node4 = Node(4);
    auto node3 = Node(3);
    auto node2 = Node(2);
    auto node1 = Node(1, vector<Node*>{&node2, &node4});
    node2.neighbors.push_back(&node1);
    node2.neighbors.push_back(&node3);
    node3.neighbors.push_back(&node2);
    node3.neighbors.push_back(&node4);
    node4.neighbors.push_back(&node1);
    node4.neighbors.push_back(&node3);
    auto result = sol.cloneGraph(&node1);
}
