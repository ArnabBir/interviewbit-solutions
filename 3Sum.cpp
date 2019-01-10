int Solution::threeSumClosest(vector<int> &A, int B) {
    
    int minDiff = INT_MAX, diff, sum, optSum = 0;
    sort(A.begin(), A.end());
    for(int i = 0; i < A.size()-2; ++i) {
        int left = i + 1, right = A.size()-1;
        while(left < right) {
            sum = A[i] + A[left] + A[right];
            if(sum == B) {
                return B;
            }
            else if(sum < B) {
                ++left;
            }
            else {
                --right;
            }
            diff = abs(sum-B);
            if(diff < minDiff) {
                minDiff = diff;
                optSum = sum;
            }
            
        }
    }
    return optSum;
}
