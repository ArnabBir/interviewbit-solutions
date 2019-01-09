char v[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

int Solution::solve(string A) {
    long count = 0, mod = 10003;
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < 10; ++j) {
            if(A[i] == v[j]) {
                count = (count + (A.size()-i)) % mod;
                break;
            }
        }
    }
    return count % mod;
}
