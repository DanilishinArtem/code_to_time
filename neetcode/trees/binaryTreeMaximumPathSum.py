from trees.btf import *


class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.res = root.val
        # this function return max path sum without split

        def dfs(root):
            if not root:
                return 0
            leftMax = dfs(root.left)
            rightMax = dfs(root.right)
            leftMax = max(leftMax, 0)
            rightMax = max(rightMax, 0)

            # compute max path sum with split
            self.res = max(self.res, root.val + leftMax + rightMax)
            return root.val + max(leftMax, rightMax)
        
        dfs(root)
        return self.res


if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print("Input:")
    btf(root)
    print("Sulution:")
    print(Solution().maxPathSum(root))