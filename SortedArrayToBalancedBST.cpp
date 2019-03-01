/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void sortedArrayToBSTUtil(TreeNode * tn, const vector<int> &A, int low, int high) {
     if(low == high)    return;
     int mid = low + (high-low)/2;
     tn->val = A[mid];
     if(low < mid) {
         tn->left = new TreeNode(0);
         sortedArrayToBSTUtil(tn->left, A, low, mid);
     }
     if(high-1 > mid) {
         tn->right = new TreeNode(0);
         sortedArrayToBSTUtil(tn->right, A, mid+1, high);
     }
 }
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    TreeNode * tn = new TreeNode(0);
    TreeNode * temp = tn;
    sortedArrayToBSTUtil(temp, A, 0, A.size());
    return tn;
}
