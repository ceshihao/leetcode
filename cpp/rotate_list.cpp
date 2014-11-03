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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k == 0) return head;
        int len = 1;
        ListNode * cur = head;
        while (cur->next)
        {
            cur = cur->next;
            ++len;
        }
        k = len - k%len;
        cur->next = head;
        for (int i=0; i<k; ++i)
            cur = cur->next;
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};