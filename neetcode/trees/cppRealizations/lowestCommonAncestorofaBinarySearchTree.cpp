#include "btf.h"


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while(cur != nullptr){
            if(p->val < cur->val && q->val < cur->val){
                cur = cur->left;
            }
            else if(p->val > cur->val && q->val > cur->val){
                cur = cur->right;
            }
            else{
                return cur;
            }
        }
        return nullptr;
    }
};


int main(){
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    cout << "Input:" << endl;
    btf(root);
    TreeNode* result = Solution().lowestCommonAncestor(root, root->left, root->right);
    cout << "Solution:" << endl;
    btf(result);
    return 0;
}