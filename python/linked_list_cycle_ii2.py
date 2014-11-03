# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        map = {}
        while head!=None:
            if head in map:
                return head
            else:
                map[head] = True
            head = head.next
        return None