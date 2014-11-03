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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                ListNode *slow2 = head;
                while (slow != slow2)
                {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};