string Solution::countAndSay(int A) {
    
    if(A == 1)  return "1";
    if(A == 2)  return "11";
    string s = "11";
    for(int i = 3; i <= A; ++i) {
        string next = "";
        s += (char)47;
        int count = 1;
        for(int j = 1; j < s.size(); ++j) {
            if(s[j] == s[j-1]) {
                ++count;
            }
            else {
                next += (char)('0' + count);
                next += s[j-1];
                count = 1;
            }
        }
        s = next;
    }
    return s;
}
