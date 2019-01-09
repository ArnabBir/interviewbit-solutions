int findPivot(const vector<int> &A, int low, int high) {
    
    while(low <= high) {
        
        if(A[low] < A[high])    return -1;
        else if(A[low] == A[high])    return low;
        else {
            int mid = low + (high - low) / 2;
            if(mid < high && A[mid] > A[mid+1]) {
                return mid;
            }
            else if(mid > low && A[mid-1] > A[mid]) {
                return (mid-1);
            }
            if(A[low] >= A[mid]) {
                high = mid-1;
            }
            else {
                low = mid + 1;
            }
        }
    }
    
    return high;
}

int calibrateIndex(int x, int n, int d) {
    return (x+n) % d;
}

int invCalibrateInde(int x, int n, int d) {
    return (x+d-n) % d;
}

int Solution::search(const vector<int> &A, int B) {
    
    int n = A.size();
    int pivot = findPivot(A, 0, n-1) + 1;
    int low = 0, high = n-1, mid;
    
    while(low <= high) {
        mid = low + (high - low) / 2;
        //cout<<mid<<" -> "<<A[calibrateIndex(mid, pivot, n)]<<" : ";
        if(A[calibrateIndex(mid, pivot, n)] == B) {
            return calibrateIndex(mid, pivot, n);
        }
        else if(A[calibrateIndex(mid, pivot, n)] < B) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
