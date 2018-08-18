#define MOD 1000000007

int Solution::maxSpecialProduct(vector<int> &A) {
    
    long long result = 0;
    stack<int> l, r;
    vector<int> left(A.size(), 0), right(A.size(), 0);
    for(int i = 0; i < A.size(); ++i) {
        if(i == 0) {
            left[i] = 0;
            l.push(i);
        }
        else {
            while(!l.empty()) {
                int head = l.top();
                //l.pop();
                if(A[head] > A[i]) {
                    l.push(i);
                    left[i] = head;
                    break;
                }
                else {
                    l.pop();
                }
            }
            if(l.empty()) {
                left[i] = 0;
                l.push(i);
            }
        }
    }
    
    for(int i = A.size()-1; i >= 0; --i) {
        if(i == A.size()-1) {
            right[i] = 0;
            r.push(i);
        }
        else {
            while(!r.empty()) {
                int head = r.top();
                if(A[head] > A[i]) {
                    r.push(i);
                    right[i] = head;
                    break;
                }
                else {
                    r.pop();
                }
            }
            if(r.empty()) {
                right[i] = 0;
                r.push(i);
            }
        }
    }
    
    
    // for(int i = 0; i < A.size(); ++i) cout<<left[i]<<" ";
    // cout<<"         ";
    // for(int i = 0; i < A.size(); ++i) cout<<right[i]<<" ";
    // cout<<endl;
    
    for(int i = 0; i < A.size(); ++i) {
        result = max(result, (long long )left[i] * (long long )right[i]);
    }
    
    return (int)(result % MOD);
}
