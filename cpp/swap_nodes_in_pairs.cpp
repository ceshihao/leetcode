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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        else
        {
            ListNode *tmp = head->next->next;
            head->next->next = head;
            head = head->next;
            head->next->next = swapPairs(tmp);
        }
        return head;
    }
};