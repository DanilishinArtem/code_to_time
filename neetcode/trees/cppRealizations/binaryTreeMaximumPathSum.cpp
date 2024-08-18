#include "btf.h"


class Solution {
public:
    // this function return max path sum without split
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);
        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);

        // compute max path sum with split
        res = max(res, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        res = root->val;
        // run dfs
        dfs(root);
        return res;
    }
private:
    int res;
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << "Input:" << endl;
    btf(root);
    cout << "Solution:" << endl;
    cout << Solution().maxPathSum(root) << endl;
    return 0;
}