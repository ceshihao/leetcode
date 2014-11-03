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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(-1), dummy_mid(x);
        dummy.next = &dummy_mid;
        dummy_mid.next = head;
        ListNode *front = &dummy, *mid = &dummy_mid, *cur = head;
        while (cur)
        {
            if (cur->val < x)
            {
                mid->next = cur->next;
                cur->next = front->next;
                front->next = cur;
                front = cur;
                cur = mid->next;
            }
            else
            {
                mid = mid->next;
                cur = cur->next;
            }
        }
        front->next = dummy_mid.next;
        return dummy.next;
    }
};