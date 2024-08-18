from trees.btf import *

class Solution:
    def __init__(self):
        self.result = 1

    def maxDepth1(self, root: TreeNode) -> int:
        if not root:
            return 0
        return 1 + max(self.maxDepth1(root.left), self.maxDepth1(root.right))
    
    def maxDepth2(self, root: TreeNode) -> int:
        if not root:
            return 0
        level = 0
        q = deque([root])
        while q:
            for i in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            level += 1
        return level

    def maxDepth3(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack = [[root, 1]]
        result = 1
        while stack:
            node, depth = stack.pop()
            if node:
                result = max(result, depth)
                stack.append([node.left, depth + 1])
                stack.append([node.right, depth + 1])
        return result



if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    print("Input:")
    btf(root)
    print("Sulution:")
    print(Solution().maxDepth1(root))
    print(Solution().maxDepth2(root))
    print(Solution().maxDepth3(root))