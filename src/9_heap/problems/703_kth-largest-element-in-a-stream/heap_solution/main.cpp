#include <algorithm>
#include <queue>

using namespace std;

/*  -- min heap solution
        - add items to a min heap
        - pop elements if they surpass k value
        - keep kth value as the first in the heap
    -- Time complexity:
        - O(n log n) for class creation due n times heap push (log n)
        - O(log n) due to heap push operation
    -- Space complexity: O(k)
        - priority queue of k items stored

    -- Leet Code submission results:
        Runtime: 7 ms
        Beats: 66.06%

        Memory: 33.12 MB
        Beats: 24.22%
*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : m_k(k) {
        for (int num : nums) {
            m_heap.push(num);

            if (m_heap.size() > m_k) {
                m_heap.pop();
            }
        }
    }
    
    int add(int val) {
        m_heap.push(val);

        if (m_heap.size() > m_k) {
            m_heap.pop();
        }

        return m_heap.top();
    }
private:
    int m_k;
    priority_queue<int, vector<int>, greater<int>> m_heap;
};