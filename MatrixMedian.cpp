int Solution::findMedian(vector<vector<int> > &A) {

    int n = A.size(), m = A[0].size();
    int low = 0, high = 0;
    for(int i = 0; i < n; ++i) {
        low = min(low, A[i][0]);
        high = max(high, A[i][m-1]);
    }
    
    int midean = (n * m + 1)/2;
    while(low < high) {
        int mid = low + (high - low)/2;
        int count = 0;
        for(int i = 0; i < n; ++i) {
            count += upper_bound(A[i].begin(), A[i].begin() + m, mid) - A[i].begin();
        }
        if(count < midean) {
            low = mid + 1;
        }
        else  {
            high = mid;
        }
    }
    return low;
}
