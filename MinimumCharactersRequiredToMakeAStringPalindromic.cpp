int Solution::solve(string A) {
    
    int n = A.size();
    if(n < 2)   return 0;
    int maxLen = 1;
    for(int i = 1; i <= n; ++i) {
        string subA = A.substr(0,i);
        string revA = subA;
        reverse(revA.begin(), revA.end());
        if(subA == revA && subA.size() > maxLen) {
            maxLen = subA.size();
        }
    }
    return n - maxLen;
}
