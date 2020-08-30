vector<int> Solution::solve(vector<vector<int> > &A) {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    int n = A.size();
    for(int i = 0; i < n; ++i) {
        if(A[i].size()) {
            pq.push(make_pair(A[i][0], i));
        }
    }
    vector<int> itr(n, 1);
    vector<int> result;
    while(!pq.empty()) {
        pair<int, int> x = pq.top();
        result.push_back(x.first);
        
        pq.pop();
        if(A[x.second].size() > itr[x.second]) {
            pq.push(make_pair(A[x.second][itr[x.second]], x.second));
            ++itr[x.second];
        }
    }
    return result;
}
