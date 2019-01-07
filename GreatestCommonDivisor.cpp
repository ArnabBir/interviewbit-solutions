int Solution::gcd(int A, int B) {
    
    int temp;
    if(A < B)   swap(A, B);

    while(B != 0) {
        temp = B;
        B = A % B;
        A = temp;
    }

    return A;
}
