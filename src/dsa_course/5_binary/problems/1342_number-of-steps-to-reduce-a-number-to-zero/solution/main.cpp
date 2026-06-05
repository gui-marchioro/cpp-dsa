/*  -- Bitwise operation solution
        - uses a property o bitwise where
            - >> 1 is like dividing the number by 2
        - uses & 1 to see if the number is odd
    -- Time complexity: O(log(n))
        - depending on the size input log(n) steps will result
    -- Space complexity: O(1)
        - one int and a bool var

    -- Leet Code submission results:
        Runtime: 0 ms
        Beats: 100.00%

        Memory: 7.97 MB
        Beats: 43.74%
*/


class Solution {
public:
    int numberOfSteps(int num) {
        int stepsToDecay = 0;
        while (num > 0) {
            bool isOdd = num & 1;
            if (isOdd) {
                num--;
            }
            else {
                num = num >> 1;
            }
            stepsToDecay++;
        }
        return stepsToDecay;
    }
};


int main() {
    auto sol = Solution{};
    auto input = 14;
    auto missingNumber = sol.numberOfSteps(input);
    return 0;
}
