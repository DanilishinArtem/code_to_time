from trees.btf import *


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, maxVal):
            if not node:
                return 0
            res = 1 if node.val >= maxVal else 0
            maxVal = max(maxVal, node.val)
            res += dfs(node.left, maxVal)
            res += dfs(node.right, maxVal)
            return res
        
        return dfs(root, root.val)


if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(1);
    root.right = TreeNode(4);
    root.left.left = TreeNode(3);
    root.right.left = TreeNode(1);
    root.right.right = TreeNode(5);
    print("Input:")
    btf(root)
    print("Sulution:")
    print(Solution().goodNodes(root))