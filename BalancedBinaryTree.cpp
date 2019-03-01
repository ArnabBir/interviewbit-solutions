/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 
 long height(TreeNode* A) {
    if(A == NULL)   return 0;
    return 1 + max(height(A->left), height(A->right));
 }
 
int Solution::isBalanced(TreeNode* A) {
    if(A == NULL) {
        return 1;
    }
    long lh = height(A->left);
    long rh = height(A->right);
    if((abs(rh - lh) <= 1) && isBalanced(A->left) && isBalanced(A->right)) return 1;
    return 0;
}
