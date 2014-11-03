/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p, *p_n;
        p = &dummy;
        p_n = &dummy;
        for (int i=0; i<n; ++i)
            p_n = p_n->next;
        while (p_n->next)
        {
            p_n = p_n->next;
            p = p->next;
        }
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return dummy.next;
    }
};