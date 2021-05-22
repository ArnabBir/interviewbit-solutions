int Solution::climbStairs(int A) {
    vector<int> dp(A+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 1; i < A+1; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[A];
}