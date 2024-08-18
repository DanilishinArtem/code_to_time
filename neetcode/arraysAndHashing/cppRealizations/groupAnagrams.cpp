#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

// overload operator << for vector
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

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hashMap;
    for(const string& s : strs){
        vector<int> count(26, 0);
        for(char c : s){
            count[c - 'a']++;
        }
        // convert vector<int> to string for inserting to the unordered map
        string key = "";
        for(int num : count){
            key += to_string(num) + ",";
        }
        // remove last comma
        key.pop_back();
        // insert to the unordered map
        hashMap[key].push_back(s);
    }
    vector<vector<string>> result;
    for(const auto& item : hashMap){
        result.push_back(item.second);
    }
    return result;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    cout << result << endl;
    return 0;
}