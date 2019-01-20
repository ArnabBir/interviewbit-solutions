bool isHorizontal(vector<vector<char> > &A, int x, int y, int n, int m, int val) {
    for(int i = 0; i < 9; ++i) {
        if(A[x][i] == (val+'0')) {
            return false;
        }
    }
    return true;
}

bool isVertical(vector<vector<char> > &A, int x, int y, int n, int m, int val) {
    for(int i = 0; i < 9; ++i) {
        if(A[i][y] == (val+'0')) {
            return false;
        }
    }
    return true;
}

bool isSquare(vector<vector<char> > &A, int x, int y, int n, int m, int val) {
    int x_ = (x/m)*m, y_ = (y/m)*m;
    for(int i = x_; i < x_+m; ++i) {
        for(int j = y_; j < y_+m; ++j) {
            if(A[i][j] == (val+'0')) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudokuUtil(vector<vector<char> > &A, int x, int y, int n, int m) {
    
    bool next;
    if(x==n || y == n)  return true;
    if(A[x][y] != '.') {
        if(y < n-1)   next = solveSudokuUtil( A, x, y+1, n, m);
        else next = solveSudokuUtil( A, x+1, 0, n, m);
        return next;
    }
    else {
        for(int i = 1; i <= 9; ++i) {
            if(isHorizontal(A, x, y, n, m, i) && isVertical(A, x, y, n, m, i) && isSquare(A, x, y, n, m, i)) {
                A[x][y] = i + '0';                if(y < n-1)   next = solveSudokuUtil( A, x, y+1, n, m);
                else next = solveSudokuUtil( A, x+1, 0, n, m);
                if(next)    return true;
                else A[x][y] = '.';
            }
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    
    int n = A.size();
    int m = sqrt(n);
    solveSudokuUtil( A, 0, 0, n, m);
}
