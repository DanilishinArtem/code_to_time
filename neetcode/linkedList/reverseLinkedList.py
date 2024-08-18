# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        while head:
            next = head.next
            head.next = prev
            prev = head
            head = next
        return prev

if __name__ == "__main__":
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    temp = head
    print("Input:")
    while temp:
        print(temp.val)
        temp = temp.next
    print("Solution:")
    head = Solution().reverseList(head)
    while head:
        print(head.val)
        head = head.next