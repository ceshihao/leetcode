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
        ListNode dummy_left(-1), dummy_right(-1);
        ListNode *left = &dummy_left, *right = &dummy_right, *cur = head;
        while (cur)
        {
            if (cur->val < x)
            {
                left->next = cur;
                left = left->next;
            }
            else
            {
                right->next = cur;
                right = right->next;
            }
            cur = cur->next;
        }
        left->next = dummy_right.next;
        right->next = NULL;
        return dummy_left.next;
    }
};