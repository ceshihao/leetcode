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
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        
        ListNode *fast = head, *slow = head, *prev = head;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        slow = reverse(slow);
    
        ListNode *cur = head;
        ListNode *tmp;
        while (cur->next)
        {
            tmp = cur->next;
            cur->next = slow;
            slow = slow->next;
            cur->next->next = tmp;
            cur = tmp;
        }
        cur->next = slow;
    }
    
    ListNode * reverse(ListNode *head){
        if (head == NULL || head->next == NULL) return head;
        ListNode *prev = head;
        for (ListNode *curr = head->next, *next = curr->next; curr;prev = curr, curr = next, next = next ? next->next : NULL) {
            curr->next = prev;
        }
        head->next = NULL;
        return prev;
    }
};