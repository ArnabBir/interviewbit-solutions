/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int k; 
int Solution::kthsmallest(TreeNode* A, int B) {
    //if(A == NULL)   return k;
    k = B;
    if(A->left != NULL) kthsmallest(A->left, k);
    --k;
    if(k == 0)  return A->val;
    if(A->right != NULL) kthsmallest(A->right, k);
}
