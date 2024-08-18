#include <iostream>
#include <string>
#include <set>
using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int l = 0, r = 1;
        int maxLen = 0;
        while (r <= s.size()) {
            string sub = s.substr(l, r - l);
            set<char> temp;
            for (int i = l; i < r; i++) {
                temp.insert(s[i]);
            }
            if (sub.size() == temp.size()) {
                maxLen = max(maxLen, temp.size());
                r += 1;
            }
            else {
                l += 1;
            }
        }
        return maxLen;
    }
};


int main(){
    string s = "pwwkew";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}







// if len(s) == 0:
//     return 0
// l, r = 0, 1
// maxLen = 0
// while r <= len(s):
//     temp = s[l:r]
//     if len(temp) == len(set(temp)):
//         maxLen = max(maxLen, len(temp))
//         r += 1
//     else:
//         l += 1
// return maxLen