#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    map<char, int> s_s;
    map<char, int> t_t;
    for(size_t i = 0; i < s.size(); i++){
        s_s[s[i]]++;
        t_t[t[i]]++;
    }

    for(size_t i = 0; i < s.size(); i++){
        if(s_s[s[i]] != t_t[s[i]]){
            return false;
        }
    }
    return true;
};

int main(){
    string s = "anagram";
    string t = "nagaram";
    cout << isAnagram(s, t) << endl;
    return 0;
}