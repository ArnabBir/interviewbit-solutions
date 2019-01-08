void Solution::arrange(vector<int> &a) {
    
    int temp = 0, temp2 = 0, count = a.size();
    int n = a.size();
    
    for(int i = 0; i < n; ++i) {
        temp = a[i] % n;
        a[i] = n * (a[temp]%n) + temp;
    }
    
    for(int i = 0; i < n; ++i) {
        a[i] /= n;
    }
    
}
