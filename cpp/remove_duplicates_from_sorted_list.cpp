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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *tmp = head;
        while (tmp)
        {
            if (!tmp->next)
                break;
            else
                if (tmp->val == tmp->next->val)
                {
                    tmp->next = tmp->next->next;
                }
                else
                    tmp = tmp->next;
        }
        return head;
    }
};