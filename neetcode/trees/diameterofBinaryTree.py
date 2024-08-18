from trees.btf import *


class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.result = 0
        
        # dfs algorithm
        def dfs(curr):
            if not curr:
                return 0
            left = dfs(curr.left)
            right = dfs(curr.right)
            self.result = max(self.result, left + right)
            return 1 + max(left, right)
        
        dfs(root)
        return self.result


if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    print("Input:")
    btf(root)
    print("Sulution:")
    print(Solution().diameterOfBinaryTree(root))