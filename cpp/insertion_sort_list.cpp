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
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN), *cur = head, *prev = &dummy;
        dummy.next = head;
        
        while (cur)
        {
            ListNode *tmp_cur = dummy.next, *tmp_prev = &dummy;
            ListNode *tmp = cur->next;
            while (tmp_cur != cur)
            {
                if (tmp_cur->val > cur->val)
                {
                    tmp_prev->next = cur;
                    cur->next = tmp_cur;
                    break;
                }
                tmp_cur = tmp_cur->next;
                tmp_prev = tmp_prev->next;
            }
            if (tmp_cur == cur)
            {
                prev = prev->next;
                cur = cur->next;
            }
            else
            {
                prev->next = tmp;
                cur = tmp;
            }
        }
        return dummy.next;
    }
};