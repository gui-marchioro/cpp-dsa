#include <iostream>
#include <vector>

using namespace std;


vector<int> BubbleSort(vector<int> &nums)
{
    int size = static_cast<int>(nums.size());
    bool isSorted = true;
    if (size < 2)
    {
        // special case where less than 2 elements inside the vector
        // can be considered already sorted
        return nums;
    }
    for (int i = 0; i < size; i++)
    {
        // left pointer to loop all elements
        for (int j = 1; j < size -i; j++)
        {
            // right pointer, to inner loop all elements
            // as an optimization it loops until (size -i)
            // since each iteration the greater number are
            // placed one by one in the end of the vector
            if (nums[i] > nums[j])
            {
                // if left greater than right, do the swap
                auto aux = nums[i];
                nums[i] = nums[j];
                nums[j] = aux;
                isSorted = false;
            }
        }
        if (isSorted)
        {
            // special case where after first iteration no swap is
            // performed, this means the vector is already sorted
            return nums;
        }
    }

    return nums;
}


void PrintVector(const vector<int> &nums)
{
    auto size = static_cast<int>(nums.size());
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << nums[i];
        if (i < size - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}


int main()
{
    auto vec = vector<int>{1, 2, 3};
    cout << "input: ";
    PrintVector(vec);
    cout << "output: ";
    PrintVector(BubbleSort(vec));
    cout << endl;
    
    vec = vector<int>{3, 2, 1};
    cout << "input: ";
    PrintVector(vec);
    cout << "output: ";
    PrintVector(BubbleSort(vec));
    cout << endl;
    
    vec = vector<int>{3, 2};
    cout << "input: ";
    PrintVector(vec);
    cout << "output: ";
    PrintVector(BubbleSort(vec));
    cout << endl;
    
    vec = vector<int>{1};
    cout << "input: ";
    PrintVector(vec);
    cout << "output: ";
    PrintVector(BubbleSort(vec));
    cout << endl;

    return 0;
}
