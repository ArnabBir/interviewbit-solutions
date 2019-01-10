int Solution::lengthOfLastWord(const string A) {
    
    int n = A.size();
    int charSeen = n;
    for(int i = n-1; i >= 0; --i) {
        if(A[i] == ' ') {
            if(charSeen != n)    return charSeen-i;
        }
        else if(charSeen == n)  charSeen = i;
    }
    return (charSeen == n) ? 0 : (charSeen+1);
}
