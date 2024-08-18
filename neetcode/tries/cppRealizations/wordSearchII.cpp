#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>

using namespace std;


class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEnd;
    
    TrieNode() {
        children = map<char, TrieNode*>();
        isEnd = false;
    }

    void addWord(string word) {
        TrieNode* cur = this;
        for(auto c : word){
            if(cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* cur, string word){
        if((r < 0 || r >= Rows || c < 0 || c >= Cols) || cur->children.find(board[r][c]) == cur->children.end() || visit.find({r, c}) != visit.end()){
            return;
        }
        visit.insert({r, c});
        word += board[r][c];
        if(cur->children[board[r][c]]->isEnd){
            res.insert(word);
        }
        dfs(board, r + 1, c, cur->children[board[r][c]], word);
        dfs(board, r - 1, c, cur->children[board[r][c]], word);
        dfs(board, r, c + 1, cur->children[board[r][c]], word);
        dfs(board, r, c - 1, cur->children[board[r][c]], word);
        visit.erase({r, c});
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Rows = board.size();
        Cols = board[0].size();
        res = set<string>();
        visit = set<tuple<char, char>>();
        TrieNode* root = new TrieNode();
        for(auto word : words){
            root->addWord(word);
        }
        for(int r = 0; r < Rows; r++){
            for(int c = 0; c < Cols; c++){
                dfs(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
private:
    int Rows;
    int Cols;
    set<string> res;
    set<tuple<char, char>> visit;
};

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& str){
    out << "[";
    for(size_t i = 0; i < str.size(); i++){
        if(i < str.size() - 1){
            out << str[i] << ",";
        }else{
            out << str[i];
        }
    }
    out << "]";
    return out;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<vector<T>>& str){
    out << "[";
    for(size_t i = 0; i < str.size(); i++){
        if(i < str.size() - 1){
            out << str[i] << ",";
        }else{
            out << str[i];
        }
    }
    out << "]";
    return out;
}

int main(){
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    cout << "Input:" << endl;
    cout << "board:" << endl;
    cout << board << endl;
    cout << "words:" << endl;
    cout << words << endl;
    cout << "Solution:" << endl;
    vector<string> result = Solution().findWords(board, words);
    cout << result << endl;
    return 0;
}