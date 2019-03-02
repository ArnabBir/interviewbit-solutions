/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    bool lr = true;
    vector<vector<int> > results;
    stack<TreeNode*> s;
    s.push(A);
    while(!s.empty()) {
        vector<int> result;
        stack<TreeNode*> temp;
        while(!s.empty()) {
            TreeNode* p = s.top();
            result.push_back(p->val);
            s.pop();
            if(lr) {
                if(p->left) temp.push(p->left);
                if(p->right) temp.push(p->right);
            }
            else {
                if(p->right) temp.push(p->right);
                if(p->left) temp.push(p->left);
            }
        }
        lr = lr ? 0:1;
        s = temp;
        results.push_back(result);
    }
    return results;
}
