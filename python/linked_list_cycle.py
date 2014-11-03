# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        head_fast = head
        while head_fast != None and head_fast.next != None:
            head = head.next
            head_fast = head_fast.next.next
            if head == head_fast:
                return True
        return False