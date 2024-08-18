#include "btf.h"
#include <climits>


class Solution {
public:
    bool dfs(TreeNode* root, int min, int max){
        if(root == nullptr){
            return true;
        }
        if(!(root->val > min && root->val < max)){
            return false;
        }
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};


int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << "Input:" << endl;
    btf(root);
    cout << "Sulution:" << endl;
    cout << Solution().isValidBST(root) << endl;
    return 0;
}