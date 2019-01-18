int Solution::lengthOfLongestSubstring(string A) {
    
    int maxLen = 0, len = 0;
    unordered_map<char, int> um;
    for(int i = 0; i < A.size(); ++i) {
        if(um[A[i]]  >= i+1 - len) {
            len = (i+1) - um[A[i]];
        }
        else {
            ++len;
        }
        um[A[i]] = i+1;
        //cout<<len<<" : ";
        maxLen = max(len, maxLen);
    }
    return maxLen;
}
