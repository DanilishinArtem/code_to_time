#include <string>
#include <iostream>
#include <map>
#include <climits>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() == 0){
            return "";
        }
        map <char, int> countT;
        map <char, int> window;

        for(int i = 0; i < t.size(); i++){
            countT[t[i]]++;
        }

        int have = 0, need = countT.size();
        string res = "";
        int resLen = INT_MAX;
        
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            window[c]++;
            if(countT.find(c) != countT.end() && window[c] == countT[c]){
                have++;
            }
            while(have == need){
                // update our result
                if(r - l + 1 < resLen){
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                // pop from the left of our window
                window[s[l]]--;
                if(countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
        }
        if(resLen == INT_MAX){
            return "";
        }
        return res;
    }
};



int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << Solution().minWindow(s, t) << endl;
    return 0;
}