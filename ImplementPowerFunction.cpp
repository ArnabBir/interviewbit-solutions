int mod(long long x, int d) {
    x %= d;
    if(x < 0)   x += d;
    return x;
}

int Solution::pow(int x, int n, int d) {

    x = mod(x, d);
    if(x == 0)  return 0;
    if(x == 1 || n == 0)  return 1;
    if(n == 1)    return x;
    long long halfPow = mod(pow(x, n/2, d), d);
    long long sqHalfPow = mod((long long) (halfPow * halfPow), d);
    if(n%2 == 0)  return sqHalfPow;
    else {
        return mod((long long) (sqHalfPow * x), d);
    }
}
