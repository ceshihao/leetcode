# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        tmp = head
        while tmp != None:
            if tmp.next == None:
                break
            else:
                if tmp.val == tmp.next.val:
                    tmp.next = tmp.next.next
                else:
                    tmp = tmp.next
        return head