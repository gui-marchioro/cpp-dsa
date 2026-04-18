#include <vector>


int FindPivotPosition(std::vector<int> &arr, int left, int right)
{
    auto i = left - 1;
    auto j = left;
    auto pivot = arr[right];
    // Algorithm here will
    // 1. advance j until pivot position
    //      a. if it finds any element lower than the pivot
    //          - swaps its position
    //          - advance i
    // 2. Place the pivot in its right position in the array
    // 3. Return the pivot position
    while (j < right)
    {
        if (arr[j] <= pivot)
        {
            i++;
            auto aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
        j++;
    }

    i++;
    auto aux = arr[i];
    arr[i] = pivot;
    arr[right] = aux;

    return i;
}

void RecursiveQuickSort(std::vector<int> &arr, int left, int right)
{
    if (left < right) // Stop recursive calls condition
    {
        auto pivot = FindPivotPosition(arr, left, right);
        RecursiveQuickSort(arr, left, pivot - 1); // Left side quick sort
        RecursiveQuickSort(arr, pivot + 1, right); // Right side quick sort
    }
}

std::vector<int> QuickSort(std::vector<int> &arr)
{
    int left = 0;
    // Simply select the pivot as the last element from the array
    auto pivot = static_cast<int>(arr.size()) - 1;
    RecursiveQuickSort(arr, left, pivot);
    return arr;
}


int main()
{
    auto input = std::vector{7, 1, 3, 5, 2, 4, 8, 9, 0};
    auto result = QuickSort(input);
    return 0;
}
