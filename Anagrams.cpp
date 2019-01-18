vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    set<int> picked;
    vector<vector<int>> results;
    int index = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(picked.find(i) != picked.end())  continue;
        vector<int> count(26, 0);
        for(int k = 0; k < A[i].size(); ++k) {
            ++count[A[i][k]-'a'];
        }
        picked.insert(i);
        vector<int> result;
        result.push_back(i+1);
        for(int j = i+1; j < A.size(); ++j) {
            if(picked.find(j) == picked.end()) {
                vector<int> count2(26, 0);
                for(int k = 0; k < A[j].size(); ++k) {
                    ++count2[A[j][k]-'a'];
                }
                bool anagram = true;
                for(int k = 0; k < 26; ++k) {
                    if(count[k] != count2[k]) {
                        anagram = false;
                        break;
                    }
                }
                if(anagram) {
                    result.push_back(j+1);
                    picked.insert(j);
                }
            }
        }
        if(result.size() > 0) {
            results.push_back(result);
        }
    }
    return results;
}
