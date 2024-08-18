#include "btf.h"
#include <stack>


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(cur || !stack.empty()){
            while(cur){
                stack.push(cur);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();
            n++;
            if(n == k){
                return cur->val;
            }
            cur = cur->right;
        }
        return -1;
    }
};


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout << "Input:" << endl;
    btf(root);
    cout << "Solution:" << endl;
    cout << Solution().kthSmallest(root, 1) << endl;
    return 0;
}