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
    bool hasCycle(ListNode *head) {
        ListNode *head_fast = head;
        while (head_fast && head_fast->next)
        {
            head = head->next;
            head_fast = head_fast->next->next;
            if (head == head_fast)
                return true;
        }
        return false;
    }
};