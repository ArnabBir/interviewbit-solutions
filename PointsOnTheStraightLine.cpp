int samePoint = 0;

double getSlope(int x1, int y1, int x2, int y2) {
    
    if(x2-x1 == 0) {
        if(y2-y1 == 0) {
            ++samePoint;
            return INT_MIN;
        } 
        else return INT_MAX;
    }
    return (double)(y1-y2) / (double) (x1-x2);
}

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    
    int n = A.size(), maxCount = 0;;
    for(int i = 0; i < n; ++i) {
        unordered_map<double, int> slopes;
        samePoint = 1;
        for(int j = i+1; j < n; ++j) {
            ++slopes[getSlope(A[i], B[i], A[j], B[j])];
        }
        int count = 0;
        for(auto x : slopes) {
            if(x.second > count && x.first != INT_MIN) {
                count = x.second;
            }
        }
        maxCount = max(count+samePoint, maxCount);
    }
    return maxCount;
}
