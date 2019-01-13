#include <string>

int Solution::evalRPN(vector<string> &A) {
    
    int result = 0;
    int temp1, temp2;
    bool firstOp = true;
    stack<int> s;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/") {
            temp2 = s.top();
            s.pop();
            temp1 = s.top();
            s.pop();
            if(A[i] == "+") {
                result = temp1 + temp2;
            }
            else if(A[i] == "-") {
                result = temp1 - temp2;
            }
            else if(A[i] == "*") {
                result = temp1 * temp2;
            }
            else if(A[i] == "/") {
                result = temp1 / temp2;
            }
            s.push(result);
        }
        else {
            stringstream ss(A[i]);
            int x = 0;
            ss >> x;
            s.push(x);
        }
    }
    return s.top();
}
