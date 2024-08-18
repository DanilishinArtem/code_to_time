#include "btf.h"


class Solution {
public:
    bool sameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if(p != nullptr && q != nullptr && p->val == q->val) {
            return sameTree(p->left, q->left) && sameTree(p->right, q->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr){
            return true;
        }
        if(root == nullptr){
            return false;
        }
        if(sameTree(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    cout << "Input:" << endl;
    cout << "Tree:" << endl;
    btf(root);
    cout << "SubTree:" << endl;
    btf(subRoot);
    cout << "Solution:" << endl;
    cout << Solution().isSubtree(root, subRoot) << endl;
    return 0;
}