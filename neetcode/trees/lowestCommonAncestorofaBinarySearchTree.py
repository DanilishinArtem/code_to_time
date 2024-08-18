from trees.btf import *


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        cur = root
        while cur:
            if p.val > cur.val and q.val > cur.val:
                cur = cur.right
            elif p.val < cur.val and q.val < cur.val:
                cur = cur.left
            else:
                return cur


if __name__ == '__main__':
    root = TreeNode(6)
    root.left = TreeNode(2);
    root.right = TreeNode(8);
    root.left.left = TreeNode(0);
    root.left.right = TreeNode(4);
    root.left.right.left = TreeNode(3);
    root.left.right.right = TreeNode(5);
    root.right.left = TreeNode(7);
    root.right.right = TreeNode(9);
    print("Input:")
    btf(root)
    print("Sulution:")
    result = Solution().lowestCommonAncestor(root, root.left, root.right)
    btf(result)