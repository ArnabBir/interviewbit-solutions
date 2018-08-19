int Solution::reverse(int A) {
    bool sign = (A >= 0);
    A = abs(A);

    long long result = 0;
    while(A > 0) {
        result = result * 10 + (A % 10);
        A /= 10;
    }
    if(result > INT_MAX || result < INT_MIN)    return 0;
    if(!sign)   result *= -1;
    return (int) result;
}
