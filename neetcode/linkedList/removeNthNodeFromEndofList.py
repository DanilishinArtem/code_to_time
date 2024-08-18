class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0, head)
        left = dummy
        right = head

        while n > 0:
            right = right.next
            n -= 1

        while right:
            right = right.next
            left = left.next

        # delete
        left.next = left.next.next
        return dummy.next


if __name__ == '__main__':
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    temp = head
    print("Input:")
    while temp:
        print(temp.val)
        temp = temp.next
    print("Solution:")
    head = Solution().removeNthFromEnd(head, 2)
    while head:
        print(head.val)
        head = head.next
        