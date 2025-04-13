class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # 各金額を作成する方法の数を保存するリストを初期化
        dp = [0] * (amount + 1)
        dp[0] = 1  # 金額0を作る方法は1つ（コインを使わない）

        # 各コインについて、dpリストを更新
        for coin in coins:
            for x in range(coin, amount + 1):
                dp[x] += dp[x - coin]

        # dp[amount]が、与えられたコインでamountを作成する方法の数
        return dp[amount]
