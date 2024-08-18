#ifndef BTF
#define BTF
#include <deque>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void btf(TreeNode* root) {
    if(root == nullptr){
        cout << "null" << endl;
    }

    deque<TreeNode*> queue;
    queue.push_back(root);
    while(!queue.empty()){
        TreeNode* node = queue.front();
        queue.pop_front();
        cout << node->val << endl;
        if(node->left != nullptr){
            queue.push_back(node->left);
        }
        if(node->right != nullptr){
            queue.push_back(node->right);
        }
    }
}

#endif