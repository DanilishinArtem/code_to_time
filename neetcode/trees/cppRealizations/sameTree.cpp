#include "btf.h"


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


int main(){
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    cout << "Input:" << endl;
    cout << "Tree1:" << endl;
    btf(tree1);
    cout << "Tree2:" << endl;
    btf(tree2);
    cout << "Solution:" << endl;
    cout << Solution().isSameTree(tree1, tree2) << endl;
    return 0;
}