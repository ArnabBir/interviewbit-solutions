int Solution::maxSubArray(const vector<int> &A) {
    
    int maxSumSoFar = INT_MIN, maxSumLast = 0;

    if(A.size() == 0)   return 0;
    if(A.size() == 1)   return A[0];
    
    for(int i = 0; i < A.size(); ++i) {
        maxSumLast += A[i];
        if(maxSumLast > maxSumSoFar) {
            maxSumSoFar = maxSumLast;
        }
        if(maxSumLast < 0) {
            maxSumLast = 0;
        }
    }
    
    return maxSumSoFar;
}
