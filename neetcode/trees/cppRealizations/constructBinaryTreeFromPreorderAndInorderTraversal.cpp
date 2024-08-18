#include "btf.h"
#include <vector>
#include <algorithm>


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> part1 = vector<int>(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> part2 = vector<int>(inorder.begin(), inorder.begin() + mid);
        root->left = buildTree(part1, part2);
        part1 = vector<int>(preorder.begin() + mid + 1, preorder.end());
        part2 = vector<int>(inorder.begin() + mid + 1, inorder.end());
        root->right = buildTree(part1, part2);
        return root;
    }
};


ostream& operator<<(ostream& out, const vector<int>& v){
    out << "[";
    for(size_t i = 0; i < v.size(); i++){
        if(i < v.size() - 1){
            out << v[i] << ",";
        }else{
            out << v[i];
        }
    }
    out << "]";
    return out;
};


int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* result = Solution().buildTree(preorder, inorder);
    cout << "Input:" << endl;
    cout << "preorder: " << preorder << endl;
    cout << "inorder: " << inorder << endl;
    cout << "Solution:" << endl;
    btf(result);
    return 0;
}