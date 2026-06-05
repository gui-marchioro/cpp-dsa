#include <vector>


using namespace std;
/*  -- Quick sort solution
    -- Time complexity: O(n log n) best and average case, O(n^2) worst case
        - recursive loops, divide and conquer

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.0%

        Memory: 11.78 MB
        Beats: 11.04%
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        QuickSort(nums);
    }
private:
    vector<int> QuickSort(vector<int>& nums) {
        // Entry point for quick sort
        int left = 0;
        // Pivot choosen at the end
        int right = static_cast<int>(nums.size()) - 1;
        RecursiveQuickSort(nums, left, right);
        return nums;
    }

    void RecursiveQuickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            auto pivotPos = FindPivotPosition(nums, left, right);
            RecursiveQuickSort(nums, left, pivotPos - 1);
            RecursiveQuickSort(nums, pivotPos + 1, right);
        }
    }

    int FindPivotPosition(vector<int>& nums, int left, int right) {
        auto pivot = nums[right];
        int i = left - 1;
        int j = left;
        while (j < right) {
            if (nums[j] <= pivot) {
                i++;
                auto aux = nums[i];
                nums[i] = nums[j];
                nums[j] = aux;
            }
            j++;
        }

        i++;
        auto aux = nums[i];
        nums[i] = pivot;
        nums[right] = aux;
        return i;
    }
};

int main() {
    //auto input = vector<int>{2,0,2,1,1,0};
    auto input = vector<int>{0,1};
    auto sol = Solution();
    sol.sortColors(input);
}