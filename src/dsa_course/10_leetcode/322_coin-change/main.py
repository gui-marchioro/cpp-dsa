from typing import List

""" 
- Knapsack dynamic programming algorithm
    -- Time complexity O(n*m): 
        - nested loop, one for the number of coins, other for the amount

    -- Space complexity: O(m)
        - dp array amount sized

    -- Leet Code submission results:
        Runtime: 395 ms
        Beats: 97.03%

        Memory: 19.50 MB
        Beats: 78.38%
"""

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0

        for coin in coins:
            for i in range(coin, amount + 1):
                dp[i] = min(dp[i], dp[i-coin] +1)

        return dp[amount] if dp[amount] != float('inf') else -1
