bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    int i = 0, j = 0;
    
    while(i < arrive.size()) {
        if(arrive[i] < depart[j]) {
            --K;
            ++i;
        }
        else if(arrive[i] < depart[j]) {
            ++K;
            ++j;
        }
        else {
            ++i;
            ++j;
        }
        
        if(K < 0)   return false;
    }
    
    return K >= 0;
    
}
