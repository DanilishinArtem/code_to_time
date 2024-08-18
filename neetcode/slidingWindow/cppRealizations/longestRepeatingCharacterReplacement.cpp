#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> count;
        int res = 0;
        int l = 0, maxf = 0;
        for(int r = 0; r < s.size(); r++){

            count[s[r]] = 1 + count[s[r]];
            maxf = max(maxf, count[s[r]]);
            if((r - l + 1) - maxf > k){
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};



int main(){
    string s = "ABBB";
    int k = 2;
    cout << Solution().characterReplacement(s, k) << endl;
    return 0;
}