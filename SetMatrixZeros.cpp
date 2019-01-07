void Solution::setZeroes(vector<vector<int> > &A) {
    
    set<int> x, y;
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < A[i].size(); ++j) {
            if(A[i][j] == 0) {
                x.insert(i);
                y.insert(j);
            }
        }
    }
    for(int i = 0; i < A.size(); ++i) {
        for(auto & j : y) {
            A[i][j] = 0;
        }
    }
    
    for(int i = 0; i < A[0].size(); ++i) {
        for(auto & j : x) {
            A[j][i] = 0;
        }
    }
}
