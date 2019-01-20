void permuteUtil(vector<int> &A, vector<bool> &visited, vector<int> &temp, vector<vector<int> > &perm, int n) {
    
    if(temp.size() == n) {
        perm.push_back(temp);
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            temp.push_back(A[i]);
            visited[i] = true;
            permuteUtil(A, visited, temp, perm, n);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    int n = A.size();
    vector<bool> visited(n, false);
    vector<vector<int> >    perm;
    vector<int> temp;
    permuteUtil(A, visited, temp, perm, n);
    return perm;
}
