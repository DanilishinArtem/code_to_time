from trees.btf import *


class Solution:
    def __init__(self):
        self.hash = {}

    def rightSideViewMySolution(self, root: TreeNode) -> list[int]:
        def dfs(node, level: int, side: str):
            if not node:
                return
            if level not in self.hash:
                self.hash[level] = [(node.val, side)]
                # self.hash[level] = [side]
            else:
                self.hash[level].append((node.val,side))
                # self.hash[level].append(side)
            dfs(node.right, level + 1, 'r')
            dfs(node.left, level + 1, 'l')

        dfs(root, 0, 'r')
        result = []
        for i in self.hash.keys():
            result.append(self.hash[i][0][0])
        return result
    
    def rightSideView(self, root: TreeNode) -> list[int]:
        res = []
        q = deque([root])
        while q:
            rightSide = None
            for i in range(len(q)):
                node = q.popleft()
                if node:
                    rightSide = node
                    q.append(node.left)
                    q.append(node.right)
            if rightSide:
                res.append(rightSide.val)
        return res





if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(4)

    # root = TreeNode(1)
    # root.left = TreeNode(2)

    print("Input:")
    btf(root)
    print("Sulution:")
    print("MySolution")
    MySolution = Solution().rightSideViewMySolution(root)
    print(MySolution)
    print("NeetCode")
    NeetCode = Solution().rightSideView(root)
    print(NeetCode)
