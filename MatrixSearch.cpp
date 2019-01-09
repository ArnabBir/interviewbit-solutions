int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    
    int n = A.size(), m = A[0].size();
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(binary_search(A[mid].begin(), A[mid].end(), B)) {
            return 1;
        }
        else {
            if(A[mid][0] > B ) {
                high = mid-1;
            }
            else if(A[mid][m-1] < B) {
                low = mid+1;
            }
            else {
                return 0;
            }
        } 
    }
    return 0;
}
