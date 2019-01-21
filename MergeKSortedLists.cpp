/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct comp {
    bool operator()( pair<int, int> p1, pair<int, int> p2) {
        return p1.first > p2.first;
    }
 };
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    
    int n = A.size();
    ListNode * head = new ListNode(0);
    ListNode * temp = head;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for(int i = 0; i < n; ++i) {
        if(A[i] != NULL) {
            pq.push(make_pair(A[i]->val, i));
            A[i] = A[i]->next;
        }
    }
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        temp->next = new ListNode(0);
        temp = temp->next;
        temp->val = p.first;
        if(A[p.second] != NULL) {
            pq.push(make_pair(A[p.second]->val, p.second));
            A[p.second] = A[p.second]->next;
        }
    }
    return head->next;
}
