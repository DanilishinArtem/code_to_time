class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        temp1, temp2 = l1, l2
        while temp1.next or temp2.next:
            if not temp1.next:
                temp1.next = ListNode(0)
            if not temp2.next:
                temp2.next = ListNode(0)
            temp1 = temp1.next
            temp2 = temp2.next

        out = ListNode(0)
        cur = out
        while l1 and l2:
            if cur.val + l1.val + l2.val >= 10:
                cur.next = ListNode((cur.val + l1.val + l2.val) // 10)
                cur.val = ((cur.val + l1.val + l2.val) % 10)
            else:
                if l1.next or l2.next:
                    cur.next = ListNode(0)
                cur.val = (cur.val + l1.val + l2.val)

            cur = cur.next
            l1 = l1.next
            l2 = l2.next
        return out



if __name__ == "__main__":
    # l1 = ListNode(2, ListNode(4, ListNode(3)))
    # l2 = ListNode(5, ListNode(6, ListNode(4)))

    l1 = ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9)))))))
    l2 = ListNode(9, ListNode(9, ListNode(9, ListNode(9))))
    out = Solution().addTwoNumbers(l1, l2)
    while out:
        print(out.val)
        out = out.next