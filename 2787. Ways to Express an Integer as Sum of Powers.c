/*
2787. Ways to Express an Integer as Sum of Powers
Solved
Medium
Topics
conpanies icon
Companies
Hint
Given two positive integers n and x.

Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

Since the result can be very large, return it modulo 109 + 7.

For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

 

Example 1:

Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 32 + 12 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
Example 2:

Input: n = 4, x = 1
Output: 2
Explanation: We can express n in the following ways:
- n = 41 = 4.
- n = 31 + 11 = 4.
 

Constraints:

1 <= n <= 300
1 <= x <= 5
*/

int numberOfWays(int n, int x) {
    const int MOD = 1e9 + 7;
    long long dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int check_num = 1; check_num <= n; check_num++) {
        long long check_num_pow = (long long)pow(check_num , x);
        for (int target_sum = 0; target_sum <= n; target_sum++) {
            if (target_sum < check_num_pow){
                dp[check_num][target_sum] = dp[check_num - 1][target_sum];
            }else{
                dp[check_num][target_sum] = (dp[check_num - 1][target_sum] + dp[check_num - 1][target_sum - check_num_pow]) % MOD;
            }
        }
    }

    return dp[n][n];    
}
