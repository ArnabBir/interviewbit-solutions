/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int maxH = 1;
 
 void maxDepthUtil(TreeNode* A, int h) {
     if(A->left == NULL && A->right == NULL) return;
     ++h;
     if(A->left != NULL) {
         maxH = max(h, maxH);
         maxDepthUtil(A->left, h);
     }
     if(A->right != NULL) {
         maxH = max(h, maxH);
         maxDepthUtil(A->right, h);
     }
 }
 
int Solution::maxDepth(TreeNode* A) {
    maxDepthUtil(A, );
    return maxH;
}
