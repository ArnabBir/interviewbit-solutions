char getChars(int x, int n) {
    if(x <= 1)  return x+'0';
    return ((x-2)*3+n)+'a';
}

void letterCombinationsUtils(string A, vector<string> &results, int curr, int n) {
    
    if(curr >= n)   return;
    vector<string> newResults;
    for(int i = 0; i < results.size(); ++i) {
        string temp = results[i];
        if(A[curr] > '1') { 
            if(A[curr] <= '6') {
                for(int j = 0; j < 3; ++j) {
                    newResults.push_back(temp + getChars(A[curr]-'0', j));
                }
            }
            else if(A[curr] == '7'){
               for(int j = 0; j < 4; ++j) {
                    newResults.push_back(temp + (char)('a' + 15 + j));
                } 
            }
            else if(A[curr] == '8') {
                for(int j = 0; j < 3; ++j) {
                    newResults.push_back(temp + (char)('a' + 19 + j));
                }
            }
            else if(A[curr] == '9') {
                for(int j = 0; j < 4; ++j) {
                    newResults.push_back(temp + (char)('a' + 22 + j));
                }
            }
        }
        else {
            newResults.push_back(temp + A[curr]);
        }
    }
    results = newResults;
    letterCombinationsUtils(A, results, curr+1, n);
}

vector<string> Solution::letterCombinations(string A) {
    
    vector<string> results;
    results.push_back("");
    letterCombinationsUtils(A, results, 0, A.size());
    return results;
}
