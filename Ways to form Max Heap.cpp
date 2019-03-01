long long dp[105];  
long long nck[105][105];  
  
long long qwe[105];  
  
long long choose(int n, int k) 
{ 
    if (k > n) 
        return 0LL; 
    if (n <= 1LL) 
        return 1LL; 
    if (k == 0LL) 
        return 1LL; 
  
    if (nck[n][k] != -1) 
        return nck[n][k]; 
  
    long long answer = choose(n - 1, k - 1)%1000000007LL + choose(n - 1, k)%1000000007LL; 
    nck[n][k] = answer%1000000007LL; 
    return answer%1000000007LL; 
} 
  
// calculate l for give value of n 
int getLeft(int n) 
{ 
    if (n == 1) 
        return 0;   
    int h = qwe[n]; 
    int last = n - ((1 << h) - 1);  
    if (last >= (numh / 2)) 
        return (1 << h) - 1; // (2^h) - 1 
    else
        return (1 << h) - 1 - ((numh / 2) - last); 
} 
  
long long numberOfHeaps(int n) 
{ 
    if (n <= 1LL) 
        return 1LL; 
  
    if (dp[n] != -1LL) 
        return dp[n]; 
  
    int left = getLeft(n); 
    long long ans = ((choose(n - 1, left)%1000000007LL * numberOfHeaps(left)%1000000007LL)%1000000007LL) *  
                             numberOfHeaps(n - 1 - left)%1000000007LL ; 
    return dp[n] = (ans%1000000007LL); 
    
}   
 
int Solution:: solve(int n) 
{ 
    for (int i = 0; i <= n; i++) 
        dp[i] = -1; 
  
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++) 
            nck[i][j] = -1; 
  
    int currLog2 = -1; 
    int currPower2 = 1; 
  
    for (int i = 1; i <= n; i++) 
    { 
        if (currPower2 == i) 
        { 
            currLog2++; 
            currPower2 *= 2; 
           
        } 
        qwe[i] = currLog2; 
    } 
  
    return numberOfHeaps(n); 
}
