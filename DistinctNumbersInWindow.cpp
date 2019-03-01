vector<int> Solution::dNums(vector<int> &A, int B) {
    
    unordered_map<int, int> um;
    int last = -1;
    vector<int> result;
    for(int i = 0; i < A.size(); ++i) {
        ++um[A[i]];
        if(i >= B-1) {
            result.push_back(um.size());
            if(um[A[i-B+1]] == 1) {
              um.erase(A[i-B+1]);  
            }
            else {
              --um[A[i-B+1]];  
            }
        }
    }
    return result;
}
