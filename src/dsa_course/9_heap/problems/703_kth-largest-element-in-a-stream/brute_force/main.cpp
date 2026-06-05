#include <vector>
#include <algorithm>

using namespace std;

/*  -- sort on class creation + insert solution on adition
        - traverse each number
        - compare it with any other number in the vector
    -- Time complexity:
        - O(n log n) for class creation due to sort operation
        - O(n) for number add due to vector insert operation
    -- Space complexity: O(n)
        - vector of n items stored

    -- Leet Code submission results:
        Runtime: 55 ms
        Beats: 5.03%

        Memory: 33.30 MB
        Beats: 5.94%
*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        m_nums = nums;
        std::sort(m_nums.begin(), m_nums.end(), std::greater<int>());
    }
    
    int add(int val) {
        auto pos = std::lower_bound(
            m_nums.begin(),
            m_nums.end(),
            val,
            std::greater<int>()
        );
        m_nums.insert(pos, val);
        int numsSize = m_nums.size();
        if (numsSize <= m_k) {
            return m_nums[numsSize-1];
        }
        return m_nums[m_k-1];
    }
private:
    int m_k;
    vector<int> m_nums;
};