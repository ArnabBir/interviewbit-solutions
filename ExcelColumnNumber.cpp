int Solution::titleToNumber(string A) {
    
    int colNo = 0;
    for(int i = A.length()-1; i >= 0; --i) {
        colNo += (A[i] - 'A' + 1) * pow(26, A.length() - i - 1);
    }
    return colNo;
}
