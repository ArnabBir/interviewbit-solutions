string Solution::longestPalindrome(string A) {
    
    int n = A.size();
    vector<vector<bool>> dp(n);
    for(int i = 0; i < n; ++i) {
        vector<bool> v(n-i, false);
        dp[i] = v;
    }

    int maxLen = (A.size() > 0) ? 1 : 0;
    int startInd = 0;
    
    for(int i = 0; i < n; ++i) {
        dp[i][0] = true;
    }
    for(int i = n-2; i >= 0; --i) {
        if(A[i] == A[i+1]) {
            dp[i][1] = true;
            maxLen = 2;
            startInd = i;
        }
    }
    for(int l = 3; l <= n; ++l) {
        for(int i = 0; i < n-(l-1); ++i) {
            if(dp[i+1][l-3] && A[i] == A[i+l-1]) {
                dp[i][l-1] = true;
                if(l > maxLen) {
                    startInd = i;
                    maxLen = l;
                }
            }
        }
    }
    return A.substr(startInd, maxLen);
}
