/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    
    ListNode * sm = new ListNode(0);
    ListNode * lr = new ListNode(0);
    ListNode * temp = A;
    ListNode * headSm = sm;
    ListNode * headLr = lr;
    while(temp != NULL) {
        if(temp->val < B) {
            //sm->val = temp->val;
            sm->next = new ListNode(temp->val);
            sm = sm->next;
        }
        else {
            //lr->val = temp->val;
            lr->next = new ListNode(temp->val);
            lr = lr->next;
        }
        temp = temp->next;
    } 
    sm->next = headLr->next;
    return headSm->next;
}
