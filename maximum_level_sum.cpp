int Solution::solve(TreeNode* A) {
    unordered_map<int, int> sum;
    queue<pair<int, TreeNode *>> q;
    if(!A) return 0;
    q.push(make_pair(0, A));
    while(!q.empty()) {
        pair<int, TreeNode *> p = q.front();
        int depth = p.first;
        TreeNode * t = p.second;
        sum[depth] += t->val; 
        q.pop();
        if(t->left) {
            q.push(make_pair(depth+1, t->left));
        }
        if(t->right) {
            q.push(make_pair(depth+1, t->right));
        }
    }
    int ans = 0;
    for(auto & m : sum) {
        ans = max(ans, m.second);
    }
    return ans;
}
