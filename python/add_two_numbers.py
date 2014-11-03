# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        carry = 0
        p = ListNode(0)
        head = p
        while l1 != None or l2 != None or carry != 0:
            if l1 == None and l2 == None:
                result = carry
            elif l1 == None:
                result = l2.val + carry
                l2 = l2.next
            elif l2 == None:
                result = l1.val + carry
                l1 = l1.next
            else:
                result = l1.val+l2.val+carry
                l1 = l1.next
                l2 = l2.next
            if result>9:
                result -= 10
                carry = 1
            else:
                carry = 0
            tmp = ListNode(result)
            p.next = tmp
            p = p.next
        return head.next