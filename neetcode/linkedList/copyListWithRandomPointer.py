class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

        
class Solution(object):
    def copyRandomList(self, head):
        oldToCopy = {None : None}
        curr = head
        while curr:
            copy = Node(curr.val)
            oldToCopy[curr] = copy
            curr = curr.next
        
        curr = head
        while curr:
            copy = oldToCopy[curr]
            copy.next = oldToCopy[curr.next]
            copy.random = oldToCopy[curr.random]
            curr = curr.next
        return oldToCopy[head]


if  __name__ == '__main__':
    temp = [Node(7), Node(13), Node(11), Node(10), Node(1)]
    temp[0].next = temp[1]
    temp[1].next = temp[2]
    temp[2].next = temp[3]
    temp[3].next = temp[4]
    temp[0].random = None
    temp[1].random = temp[0]
    temp[2].random = temp[4]
    temp[3].random = temp[2]
    temp[4].random = temp[0]

    print("Input:")
    start = temp[0]
    while start:
        print(str(start.val) + " " + str(start.random.val if start.random else None))
        start = start.next
    
    print("Output:")
    start = Solution().copyRandomList(temp[0])
    while start:
        print(str(start.val) + " " + str(start.random.val if start.random else None))
        start = start.next