#include <string>
#include <iostream>
#include <map>

using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEnd;
    
    TrieNode() {
        children = map<char, TrieNode*>();
        isEnd = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto c : word){
            if(cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(auto c : word){
            if(cur->children.find(c) == cur->children.end()){
                return false;
            }
            cur = cur->children[c];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto c : prefix){
            if(cur->children.find(c) == cur->children.end()){
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
private:
    TrieNode* root;
};


int main(){
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    return 0;
}