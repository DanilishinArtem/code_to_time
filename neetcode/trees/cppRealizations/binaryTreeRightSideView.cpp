#include "btf.h"
#include <vector>
#include <queue>


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> q = {root};
        while(!q.empty()){
            TreeNode* rightSide = nullptr;
            for(int i = 0; i < q.size(); i++){
                TreeNode* node = q.front();
                q.pop_front();
                if(node != nullptr){
                    rightSide = node;
                }
                if(node->left != nullptr){
                    q.push_back(node->left);
                }
                if(node->right != nullptr){
                    q.push_back(node->right);
                }
            }
            if(rightSide != nullptr){
                res.push_back(rightSide->val);
            }
        }
        return res;
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(4);
    cout << "Input:" << endl;
    btf(root);
    cout << "Solution:" << endl;
    vector<int> result = Solution().rightSideView(root);
    cout << "[ ";
    for(auto item : result){
        cout << item << ", ";
    }
    cout << "]" << endl;
    return 0;
}