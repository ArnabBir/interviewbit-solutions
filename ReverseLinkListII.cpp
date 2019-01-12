/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    ListNode * ptr1 = A, * ptr2 = A;
    stack<int> s;
    for(int i = 0; i < B-1; ++i) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    for(int i = B; i <= C; ++i) {
        s.push(ptr2->val);
        ptr2 = ptr2->next;
    }
    while(!s.empty()) {
        ptr1->val = s.top();
        s.pop();
        ptr1 = ptr1->next;
    }
    return A;
}
