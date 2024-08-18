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


class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    bool dfs(int j, TrieNode* root, string word){
        TrieNode* cur = root;
        for(int i = j; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(auto child : cur->children){
                    if(dfs(i + 1, child.second, word)){
                        return true;
                    }
                }
                return false;
            }else{
                if(cur->children.find(c) == cur->children.end()){
                    return false;
                }
                cur = cur->children[c];
            }
        }
        return cur->isEnd;
    }

    void addWord(string word) {
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
        return dfs(0, root, word);
    }
private:
    TrieNode* root;
};


int main(){
    WordDictionary* wordDictionary = new WordDictionary();
    wordDictionary->addWord("bad");
    wordDictionary->addWord("dad");
    wordDictionary->addWord("mad");
    cout << wordDictionary->search("pad") << endl; // return False
    cout << wordDictionary->search("bad") << endl; // return True
    cout << wordDictionary->search(".ad") << endl; // return True
    cout << wordDictionary->search("b..") << endl; // return True
    return 0;
}