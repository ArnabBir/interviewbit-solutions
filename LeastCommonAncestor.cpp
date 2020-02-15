/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int ans = -1;
 
 bool lcaUtil(TreeNode* A, int B, int C) {
     if(!A)  return false;
     bool l = lcaUtil(A->left, B, C);
     bool r = lcaUtil(A->right, B, C);
     if(A->val == B || A->val == C) {
         if(B == C || l || r) {
             ans = A->val;
             return true;
         }
         return true;
     }
     if(l && r) {
         ans = A->val;
         return true;
     }
     if(l && r )  return false;
     return l || r;
 }
int Solution::lca(TreeNode* A, int B, int C) {
    ans = -1;
    lcaUtil(A, B, C);
    return ans;
}
