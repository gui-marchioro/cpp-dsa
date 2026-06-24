#include <unordered_map>
#include <vector>

using namespace std;

/*  -- Graph DFS traversal
        - given a root node
        - have a hashmap containing val as a key and Node instance
        - traverse nodes using DFS
            - returning cloned node if exists
            - or creating new clone if not
        - avoid to repeat looking for nodes already in the hashmap
    -- Time complexity: O(n)
        - all nodes are visited at least once
    -- Space complexity: O(n)
        - all nodes are saved in memory

    -- Leet Code submission results:
        Runtime: 3 ms
        Beats: 68.30%

        Memory: 12.22 MB
        Beats: 26.88%
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
        if (!node) {
            return nullptr;
        }

        unordered_map<int, Node*> clones;
        return dfs(node, clones);
    }
private:
    Node* dfs(Node* node, unordered_map<int, Node*>& clones) {
        if (clones.count(node->val)) {
            return clones[node->val];
        }

        Node* clone = new Node(node->val);
        clones[node->val] = clone;
        for (auto& neigh : node->neighbors) {
            clone->neighbors.push_back(dfs(neigh, clones));
        }
        return clone;
    }
};