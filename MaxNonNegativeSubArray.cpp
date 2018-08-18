vector<int> Solution::maxset(vector<int> &A) {
    
    long maxSumSoFar = -1, maxSumLast = 0;
    vector<int> v;
    int l = 0, r = 0, lmax = 0, rmax = 0;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] >= 0) {
            //cout<<i<<" ";
            l = i;
            maxSumLast = 0;
            while(A[i] >= 0 && i < A.size()){ maxSumLast += A[i++];}
        }
            if(maxSumLast > maxSumSoFar) {
                //cout<<"HEllo ";
                maxSumSoFar = maxSumLast;
                lmax = l;
                rmax = i;
            }
        
    }
    //cout<<lmax<<" "<<rmax<<" "<<maxSumSoFar<<endl;
    for(int i = lmax; i < rmax; ++i) {
        v.push_back(A[i]);
    }
    
    return v;
}
