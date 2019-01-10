int Solution::romanToInt(string A) {
    
    int num = 0;
    int C = 0, X = 0, I = 0;
    for(int i = 0; i < A.size(); ++i) {
        
        switch(A[i]) {
            case 'M':
                num += 1000;
                if(C > 0) {
                    num -= 2 * C * 100;
                }
                break;
            case 'D':
                num += 500;
                if(C > 0) {
                    num -= 2 * C * 100;
                }
                break;
            case 'C':
                num += 100;
                if(X > 0) {
                    num -= 2 * X * 10;
                }
                ++C;
                break;
            case 'L':
                num += 50;
                if(X > 0) {
                    num -= 2 * X * 10;
                }
                break;
            case 'X':
                num += 10;
                if(I > 0) {
                    num -= 2 * I;
                }
                ++X;
                break;
            case 'V':
                num += 5;
                if(I > 0) {
                    num -= 2 * I;
                }
                break;
            case 'I':
                num += 1;
                ++I;
                break;
        }
    }
    
    return num;
}
