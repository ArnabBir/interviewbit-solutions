int Solution::canJump(vector<int> &A) {
    int n = A.size();
    vector<bool> dp(n, false);
    dp[n-1] = true;
    for(int i = n-2; i >= 0; --i) {
        for(int j = 0; j <= A[i] && j < n-1; ++j) {
            if(dp[i+j]) {
                dp[i] = true;
            }
        }
    }
    return (int)dp[0];
}
