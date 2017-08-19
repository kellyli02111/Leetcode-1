# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        dummy = ListNode(0)
        curNode = dummy
        n1 = l1
        n2 = l2
        while(n1 != None or n2 != None or carry):
            curSum = carry
            if(n1 != None):
                curSum += n1.val
                n1 = n1.next
            if(n2 != None):
                curSum += n2.val
                n2 = n2.next
            digit = curSum % 10
            carry = curSum / 10
            newNode = ListNode(digit)
            curNode.next = newNode
            curNode = curNode.next
        return dummy.next
            
