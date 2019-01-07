int Solution::firstMissingPositive(vector<int> &A) {
    
    int posind = 0;
    
    if(A.size() == 1) return ((A[0] == 1) ? 2:1);
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] > 0) {
            swap(A[i], A[posind]);
            ++posind;
        }
    }
    for(int i = 0; i < posind; ++i) {
        if(A[abs(A[i])-1] > 0 && abs(A[i])-1 < posind) {
            A[abs(A[i])-1] = -A[abs(A[i])-1];
        }
    }
    for(int i = 0; i < posind; ++i) {
        
        if(A[i] > 0)    return (i+1);
    }
    return A.size() + 1;
    
}
