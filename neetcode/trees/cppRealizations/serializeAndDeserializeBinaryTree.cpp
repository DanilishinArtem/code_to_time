#include "btf.h"
#include <vector>


class Codec {
public:
    void dfsSerialization(TreeNode* root) {
        if(root == nullptr){
            encode += "N";
            return;
        }
        encode += to_string(root->val);
        dfsSerialization(root->left);
        dfsSerialization(root->right);
    }

    TreeNode* dfsDeserialization() {
        if(encode[index] == 'N'){
            index++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(encode.substr(index, 1)));
        index++;
        node->left = dfsDeserialization();
        node->right = dfsDeserialization();
        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfsSerialization(root);
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        index = 0;
        encode = data;
        return dfsDeserialization();
    }
private:
    int index;
    string encode;
    TreeNode* decode;
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    cout << "Input:" << endl;
    btf(root);
    cout << "Solution:" << endl;
    string encode = Codec().serialize(root);
    cout << "Encode:" << endl;
    cout << encode << endl;
    TreeNode* decode = Codec().deserialize(encode);
    cout << "Decode:" << endl;
    btf(decode);
    return 0;
}