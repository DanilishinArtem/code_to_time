class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def reorderList(self, head):
        # find the middle
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # reverse the second half
        second = slow.next
        prev = slow.next = None # break link between two parts
        while second:
            tmp = second.next
            second.next = prev
            prev = second
            second = tmp

        # merge two parts
        first, second = head, prev
        while second:
            tmp1, tmp2 = first.next, second.next
            first.next = second
            second.next = tmp1
            first, second = tmp1, tmp2


if __name__ == '__main__':
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    temp = head
    print("Input:")
    while temp:
        print(temp.val)
        temp = temp.next
    print("Solution:")
    Solution().reorderList(head)
    while head:
        print(head.val)
        head = head.next
        