from trees.btf import *


class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        n = 0
        stack = []
        cur = root

        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            n += 1
            if n == k:
                return cur.val
            cur = cur.right


if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.left.right = TreeNode(2)
    print("Input:")
    btf(root)
    print("Sulution:")
    print(Solution().kthSmallest(root, 4))