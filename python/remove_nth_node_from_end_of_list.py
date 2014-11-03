# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        node_array = []
        tmp = head
        length = 0
        while tmp != None:
            node_array.append(tmp)
            tmp = tmp.next
            length += 1
        if length == n:
            return head.next
        else:
            node_array[length-n-1].next = node_array[length-n].next
            return head