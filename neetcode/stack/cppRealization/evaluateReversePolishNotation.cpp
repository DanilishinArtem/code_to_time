#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution{
public:
	int evalRPN(vector<char>& tokens){
		stack<int> stack;
		for(auto token : tokens){
			if(token == '+'){
				int a = static_cast<int>(stack.top());
				stack.pop();
				int b = static_cast<int>(stack.top());
				stack.pop();
				stack.push(a + b);
			}else if(token == '-'){
				int a = static_cast<int>(stack.top());
				stack.pop();
				int b = static_cast<int>(stack.top());
				stack.pop();
				stack.push(-a + b);
			}else if(token == '*'){
				int a = static_cast<int>(stack.top());
				stack.pop();
				int b = static_cast<int>(stack.top());
				stack.pop();
				stack.push(a * b);
			}else if(token == '/'){
				int a = static_cast<int>(stack.top());
				stack.pop();
				int b = static_cast<int>(stack.top());
				stack.pop();
				stack.push(b / a);
			}else{
				stack.push(static_cast<int>(token - '0'));
			}
		}
		return stack.top();
	}
};


int main(){
	vector<char> tokens = {'1', '2', '+', '3', '*', '4', '-'};
	cout << Solution().evalRPN(tokens) << endl;
	return 0;
}