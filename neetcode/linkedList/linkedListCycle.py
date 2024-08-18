class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def hasCycle(self, head):
        while head:
            if head.val == float("inf"):
                return True
            head.val = float("inf")
            head = head.next
        return False


if __name__ == "__main__":
    temp = [ListNode(3), ListNode(2), ListNode(0), ListNode(-4)]
    temp[0].next = temp[1]
    temp[1].next = temp[2]
    temp[2].next = temp[3]
    temp[3].next = temp[1]

    start = temp[0]

    print("Input:")
    for _ in range(5):
        print(start.val)
        start = start.next

    print("Solution:")
    start = temp[0]
    print(Solution().hasCycle(start))