class Solution:
    def countStrings(self, n, k): 
        # code here 
        MOD = 10**9+7
        dp = [[[0] * 2 for _ in range(k + 1)] for _ in range(n + 1)]
        dp[1][0][0] = dp[1][0][1] = 1

        for i in range(1, n):
            for j in range(k + 1):
                zero = dp[i][j][0]
                one = dp[i][j][1]

                # Append 0
                dp[i + 1][j][0] = (dp[i + 1][j][0] + zero + one) % MOD

                # Append 1 after 0
                dp[i + 1][j][1] = (dp[i + 1][j][1] + zero) % MOD

                # Append 1 after 1
                if j < k:
                    dp[i + 1][j + 1][1] = (
                        dp[i + 1][j + 1][1] + one
                    ) % MOD

        return (dp[n][k][0] + dp[n][k][1]) % MOD