string Solution::convert(string A, int B) {
    
    if(B == 1)  return A;
    int n = A.size(), x = 0;
    bool d = true;
    string s[B];
    for(int i = 0; i < B; ++i)  s[i] = "";
    string result = "";
    for(int i = 0; i < n; ++i){
        s[x] += A[i];
        if(d)   ++x;
        else --x;
        if(x == 0 || x == B-1)  d = !d;
    }
    for(int i = 0; i < B; ++i) {
        result += s[i];
    }
    return result;
}
