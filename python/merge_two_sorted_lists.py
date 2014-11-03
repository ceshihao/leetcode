# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        tmp = ListNode(0)
        l = tmp
        while l1 != None or l2 != None:
            if l1 == None:
                tmp.next = l2
                break
            elif l2 == None:
                tmp.next = l1
                break
            else:
                if l1.val>l2.val:
                    tmp.next = l2
                    l2 = l2.next
                else:
                    tmp.next = l1
                    l1 = l1.next
                tmp = tmp.next
        return l.next