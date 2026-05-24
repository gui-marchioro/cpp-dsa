#include <vector>
#include <climits>

using namespace std;

/*  -- Array based stack, tracking minimum value

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 23.25 MB
        Beats: 83.61%
*/


class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        if (val < minVal) {
            minVal = val;
        }
        items.emplace_back(val);
    }
    
    void pop() {
        int popVal = items.back();
        items.pop_back();
        if (popVal == minVal) {
            minVal = INT_MAX;
            for (int item : items) {
                if (item < minVal) {
                    minVal = item;
                }
            }
        }
    }
    
    int top() {
        return items.back();
    }
    
    int getMin() {
        return minVal;
    }
private:
    vector<int> items;
    int minVal = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */