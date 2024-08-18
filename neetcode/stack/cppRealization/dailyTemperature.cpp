#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> dailyTempeerature(vector<int>& temperatures){
        stack<int> stack;
        vector<int> res(temperatures.size(), 0);
        for(size_t i = 0; i < temperatures.size(); i++){
            while(!stack.empty() && temperatures[stack.top()] < temperatures[i]){
                int prev = stack.top();
                stack.pop();
                res[prev] = i - prev;
            }
            stack.push(i);
        }
        return res;
    }
};


ostream& operator<<(ostream& out, const vector<int>& str){
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
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = Solution().dailyTempeerature(temperatures);
    cout << result << endl;
    return 0;
}
