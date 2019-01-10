int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int minDiff = INT_MAX, curr = INT_MAX;
    
    int i = 0, j = 0, k = 0, maxVal, minVal;
    
    while(i < A.size() && j < B.size() && k < C.size()) {
        maxVal = max(A[i], max(B[j], C[k]));
        minVal = min(A[i], min(B[j], C[k]));
        curr = maxVal - minVal;
        if(curr < minDiff) {
            minDiff = curr;
            
        }
        if(A[i] == minVal) {
            ++i;
        }
        else if(B[j] == minVal) {
            ++j;
        }
        else {
            ++k;
        }
    }
    return minDiff;
}
