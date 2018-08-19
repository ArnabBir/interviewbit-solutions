#define MOD 1000000007

int Solution::hammingDistance(const vector<int> &A) {
    
    long distance = 0;
    int ones;
    
    for(int i = 0; i < 32; ++i) {
        ones = 0;
        for(int j = 0; j < A.size(); ++j) {
            if((A[j] & 1<<i)) {
                ++ones;
            }
        }
        distance += 2 * ones * (A.size() - ones);
    }
    
    return (int) (distance % MOD);
}
