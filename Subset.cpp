void createSubsets(vector<int> &A, vector<vector<int>> &subsets) {
    
    int n = A.size();
    sort(A.begin(), A.end());
    for(int i = 0; i < 1<<n; ++i) {
        vector<int> subset;
        int bit = i;
        for(int j = 0; j < n && bit; ++j) {
            if(bit%2)  {
                subset.push_back(A[j]);
            }
            bit /= 2;
        }
        subsets.push_back(subset);
    }
    sort(subsets.begin(), subsets.end());
}

vector<vector<int>> Solution::subsets(vector<int> &A) {
    
    vector<vector<int>> subsets;
        createSubsets(A, subsets);
    
    return subsets;
}
