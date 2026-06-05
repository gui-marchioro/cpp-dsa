#include <vector>


using namespace std;
/*  -- Bubble sort solution
    -- Time complexity: O(n^2)
        - loop inside loop

    -- Leet Code submission results:
        Runtime: 3 ms
        Beats: 2.75%

        Memory: 11.86 MB
        Beats: 11.04%
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        BubbleSort(nums);
    }
private:
    vector<int> BubbleSort(vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        for (int i = 0; i < size; i++) {
            bool sorted = true;
            for (int j = 1; j < size - i; j++) {
                if (nums[j-1] > nums[j]) {
                    sorted = false;
                    auto aux = nums[j-1];
                    nums[j-1] = nums[j];
                    nums[j] = aux;
                }
            }
            if (sorted) {
                return nums;
            }
        }
        return nums;
    }
};

int main() {
    auto input = vector<int>{2,0,2,1,1,0};
    //auto input = vector<int>{0,1};
    auto sol = Solution();
    sol.sortColors(input);
}