int Solution:: solve(vector<int> &A, int B, int C) {

    string digit = to_string(C);
    //reverse(digit.begin(), digit.end());
    int lenC = digit.size();
    if (A.size() == 0 || B > lenC) {
        return 0;
    }
    else if(B < lenC) {
        if(B == 1)  return A.size();
        else if(A[0] == 0){
            return (A.size()-1) * pow(A.size(), B-1);
        }
        else {
            return pow(A.size(), B);
        }
    }
    else {
        if(B ==1) {
            return upper_bound(A.begin(), A.end(), C) - A.begin();
        }
        else {
            vector<int> dp(B+1, 0), lower(11, 0);
            for(int i = 0; i < A.size(); ++i) {
                lower[A[i]+1] = 1;
            }
            for(int i = 1; i <= 10; ++i) {
                lower[i] = lower[i-1] + lower[i];
            }
            bool flag = true;
            
            for(int i = 1; i <= B; ++i) {
                int d2 = lower[digit[i-1] - '0'];
                dp[i] = dp[i-1] * A.size();
                if(i == 1 && A[0] == 0 && B != 1) {
                    d2 -= 1;
                }
                if(flag) {
                    dp[i] += d2;
                }
                flag = flag & (lower[digit[i-1] - '0'+1] == (lower[digit[i-1]-'0'] + 1));
            }
            return dp[B];
        }
    }
    
    
}
