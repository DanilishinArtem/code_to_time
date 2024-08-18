#include "btf.h"
#include <map>

class Solution {
public:
    pair<bool, int> dfs(TreeNode* root){
        if(root == nullptr){
            return {true, 0};
        }
        pair<bool, int> left = dfs(root->left);
        pair<bool, int> right = dfs(root->right);
        bool balanced = false;
        if(left.first && right.first && abs(left.second - right.second) <= 1){
            balanced = true;
        }
        return {balanced, max(left.second, right.second) + 1};
    }
    bool isBalanced(TreeNode* root) {
        pair<bool, int> result = dfs(root);
        return result.first;
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "Input:" << endl;
    btf(root);
    cout << "Solution:" << endl;
    cout << Solution().isBalanced(root) << endl;
    return 0;
}