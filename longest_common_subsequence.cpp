int Solution::solve(string A, string B) {
    
    int n = A.size();
    int m = B.size();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i < n+1; ++i) {
        for(int j = 1; j < m+1; ++j) {
            dp[i][j] = max(dp[i][j], max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + (A[i-1] == B[j-1])));
        }
    }
    return dp[n][m];
}
