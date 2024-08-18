from trees.btf import *


class Solution:
    def levelOrder(self, root: TreeNode) -> list[list[int]]:
        if not root:
            return []
        result = [[root.val]]
        q = deque([root])
        while q:
            level = []
            for i in range(len(q)):
                node = q.popleft()
                if node.left:
                    level.append(node.left.val)
                    q.append(node.left)
                if node.right:
                    level.append(node.right.val)
                    q.append(node.right)
            if level:
                result.append(level)
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
    print(Solution().levelOrder(root))