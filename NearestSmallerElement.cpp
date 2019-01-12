vector<int> Solution::prevSmaller(vector<int> &A) {
    
    stack<int> s;
    vector<int> result;
    for(int i = 0; i < A.size(); ++i) {
        while(!s.empty() && s.top() >= A[i]) {
            s.pop();
        }
        if(s.empty()) {
            result.push_back(-1);
        }
        else {
            result.push_back(s.top());
        }
        s.push(A[i]);
    }
    return result;
}
