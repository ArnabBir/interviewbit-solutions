vector<int> Solution::grayCode(int A) {
    
    vector<int> gCode;
    gCode.push_back(0);
    gCode.push_back(1);
    int bit = 1;
    for(int i = 2; i <= A; ++i) {
        bit <<= 1;
        int n = gCode.size();
        for(int j = n-1; j >= 0; --j) {
            gCode.push_back(gCode[j] + bit);
        }
    }
    
    return gCode;
}
