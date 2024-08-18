#include "btf.h"


class Solution {
public:
    int dfs(TreeNode* node, int maxVal){
        if(node == nullptr){
            return 0;
        }
        int res = 0;
        if(node->val >= maxVal){
            res++;
        }
        maxVal = max(maxVal, node->val);
        res += dfs(node->left, maxVal);
        res += dfs(node->right, maxVal);
        return res;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};



int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    cout << "Input:" << endl;
    btf(root);
    cout << "Sulution:" << endl;
    cout << Solution().goodNodes(root) << endl;
    return 0;
}