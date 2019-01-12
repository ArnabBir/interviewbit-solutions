/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    
    ListNode * head1 = A;
    ListNode * head2 = A->next;
    while(head1 != NULL && head2 != NULL) {
        int temp = head1->val;
        head1->val = head2->val;
        head2->val = temp;
        head1 = head1->next->next;
        if(head2->next == NULL)   break;
        head2 = head2->next->next;
    }
    return A;
}
