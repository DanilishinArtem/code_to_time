#include "btf.h"
#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> result = {{root->val}};
        deque<TreeNode*> q = {root};
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop_front();
                if(node->left != nullptr){
                    q.push_back(node->left);
                    level.push_back(node->left->val);
                }
                if(node->right != nullptr){
                    q.push_back(node->right);
                    level.push_back(node->right->val);
                }
            }
            if(level.size() > 0){
                result.push_back(level);
            }
        }
        return result;
        
    }
};


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "Input:" << endl;
    btf(root);
    cout << "Solution:" << endl;
    vector<vector<int>> result = Solution().levelOrder(root);
    
    cout << "[ ";
    for(auto vec : result){
        cout << "[ ";
        for(auto item : vec){
            cout << item << ", ";
        }
        cout << "], ";
    }
    cout << endl;
    return 0;
}