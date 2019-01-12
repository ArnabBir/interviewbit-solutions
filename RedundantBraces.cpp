int Solution::braces(string A) {
    
    stack<char> s;
    bool sign = false;
    for(int i = 0; i < A.size(); ++i) {
        if(A[i] == ')') {
            if(s.top() == '(')  return 1;
            else {
                sign = false;
                while(s.top() != '(') {
                    if(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/') {
                        sign = true;
                    }
                    s.pop();
                }
                s.pop();
                if(!sign)   return 1;
            }
        }
        else {
            s.push(A[i]);
        }
    }
    return 0;
}
