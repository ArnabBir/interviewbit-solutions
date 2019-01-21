/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    vector<int> result;
    stack<TreeNode *> s;
    if(A != NULL) {
        s.push(A);
    }
    while(!s.empty()) {
        TreeNode * temp = s.top();
        if(temp->left != NULL) {
            s.push(temp->left);
            temp->left = NULL;
        }
        else {
            result.push_back(temp->val);
            s.pop();
            if(temp->right != NULL) {
                s.push(temp->right);
                temp->right = NULL;
            }
        }
    }
    return result;
}
