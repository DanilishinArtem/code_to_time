from trees.btf import *


class Codec:
    def serialize(self, root):
        res = []
        def dfs(node):
            if not node:
                res.append("N")
                return
            res.append(str(node.val))
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return ",".join(res)

    def deserialize(self, data):
        vals = data.split(",")
        self.i = 0
        def dfs():
            if vals[self.i] == "N":
                self.i += 1
                return None
            node = TreeNode(int(vals[self.i]))
            self.i += 1
            node.left = dfs()
            node.right = dfs()
            return node
        return dfs()


if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2);
    root.right = TreeNode(3);
    root.right.left = TreeNode(4);
    root.right.right = TreeNode(5);

    print("Input:")
    btf(root)
    print("Sulution:")
    inconde = Codec().serialize(root)
    print("Incode:")
    print(inconde)
    decode = Codec().deserialize(inconde)
    print("Decode:")
    btf(decode)