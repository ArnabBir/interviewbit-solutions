int minS;
stack<int> s;

MinStack::MinStack() {
    minS = -1;
    s = stack<int>();
}

void MinStack::push(int x) {
    
    if(s.empty()) {
        minS = x;
        s.push(x);
        return;
    }
    
    if(x < minS) {
        s.push(2*x - minS);
        minS = x;
    }
    else s.push(x);
}

void MinStack::pop() {
    if(!s.empty()) {
        int temp = s.top();
        s.pop();
        if(temp < minS) {
            minS = 2*minS - temp;
        }
    }
}

int MinStack::top() {
    if(s.empty())   return -1;
    int temp = s.top();
    if(temp < minS) {
        return minS;
    }
    else {
        return temp;
    }
}

int MinStack::getMin() {
    if(s.empty())   return -1;
    return minS;
}

