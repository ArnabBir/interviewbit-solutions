int Solution::removeDuplicates(vector<int> &A) {
    
    for(int i = A.size()-1; i  >= 1; --i) {
        if(A[i] == A[i-1]) {
            A.erase(A.begin() + i);
        }
    }
    return A.size();
}
