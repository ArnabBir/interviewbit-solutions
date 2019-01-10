int Solution::findMinXor(vector<int> &A) {
    
    int minXor = INT_MAX, n = A.size();
    sort(A.begin(), A.end());
    for(int i = 0; i < n-1; ++i) {
        minXor = min(minXor, A[i]^A[i+1]);

    }
    return minXor;
}
