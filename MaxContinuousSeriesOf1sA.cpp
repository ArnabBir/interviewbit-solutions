vector<int> Solution::maxone(vector<int> &A, int B) {
    
    int wL = 0, wR = 0, maxL = 0, maxW = 0, count0 = 0;
    vector<int> result;
    
    while(wR < A.size()) {
        
        if(count0 <= B) {
            if(A[wR] == 0) ++count0;
            ++wR;
        }
        if(count0 > B) {
            if(A[wL] == 0)  --count0;
            ++wL;
        }
        if(wR-wL > maxW && count0 <= B) {
            maxW = wR-wL;
            maxL=wL;
        }
    }
    
    for(int i = 0; i < maxW; ++i) {
        result.push_back(maxL+i);
    }
    return result;
}
