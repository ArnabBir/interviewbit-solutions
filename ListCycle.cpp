/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode * getStartNode(ListNode * ptr , ListNode * A){
    ListNode * temp1 = ptr;
    ListNode * temp2 = ptr;
    int k = 1;
    while(temp1->next != temp2){
        k++;
        temp1 = temp1->next;
    }
    temp1 = A;
    temp2 = A;
    for(int i = 0 ; i < k ; ++i){
        temp2 = temp2->next;
    }
    while(temp2!=temp1){
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    return temp2;
} 

ListNode* Solution::detectCycle(ListNode* A) {
    
    ListNode * ptr1 = A;
    ListNode * ptr2 = A;
    while(ptr1 && ptr2 && ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        if(ptr1 == ptr2)  return getStartNode(ptr1, A);
    }
    return NULL;
}
