vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    
    unordered_map<string, int> um;
    vector<int> result;
    int n = A.size(), m = B.size();
    int len = B[0].size();
    for(int i = 0; i < m; ++i) {
        ++um[B[i]];
    }
    for(int i = 0; i < n-len*m+1; ++i) {
        unordered_map<string, int > temp(um);
        int j = i, count = 0;
        while(j < i+len*m) {
            string s = A.substr(j, len);
            if(temp[s] == 0) {
                break;
            }
            ++count;
            --temp[s];
            j += len;
        }
        if(count == m) {
            result.push_back(i);
        }
        
    }
    return result;
}
