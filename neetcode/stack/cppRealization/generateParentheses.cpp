#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    static vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<string> stack;
        string str = "";
        backtrack(result, stack, str, n, n);
        return result;
    }
private:
    static void backtrack(vector<string>& result, stack<string>& stack, string str, int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(str);
            return;
        }
        if (left > 0) {
            stack.push("(");
            backtrack(result, stack, str + "(", left - 1, right);
            stack.pop();
        }
        if (right > left) {
            stack.push(")");
            backtrack(result, stack, str + ")", left, right - 1);
            stack.pop();
        }
    }
};


int main() {
    int n = 3;
    vector<string> result = Solution::generateParenthesis(n);
    for (string str : result) {
        cout << str << endl;
    }
    return 0;
}