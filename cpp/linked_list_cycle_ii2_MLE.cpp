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
        unordered_map<ListNode *, bool> map;
        while (head)
        {
            if (map.find(head) != map.end())
                return head;
            else
                map[head] = true;
            head++;
        }
        return NULL;
    }
};