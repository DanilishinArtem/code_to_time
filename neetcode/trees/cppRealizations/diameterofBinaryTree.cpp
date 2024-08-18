#include "btf.h"


class Solution {
public:
    int dfs(TreeNode* curr){
        if(curr == nullptr){
            return 0;
        }
        int left = dfs(curr->left);
        int right = dfs(curr->right);
        result = max(result, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // dfs algorithm
        dfs(root);
        return result;
    }
private:
    int result = 0;
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << "Input:" << endl;
    btf(root);
    cout << "Solution:" << endl;
    cout << Solution().diameterOfBinaryTree(root) << endl;
    return 0;
}