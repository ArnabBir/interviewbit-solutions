int Solution::colorful(int A) {
    
    unordered_map<long long, bool> um;
    string s = to_string(A);
    
    for(int i = 0; i < s.size(); ++i) {
        long long prod = 1;
        for(int j = i; j < s.size(); ++j) {
            prod *= s[j] - '0';
            if(um[prod]) {
                return 0;
            }
            um[prod] = true;
        }
    }
    
    return 1;
}
