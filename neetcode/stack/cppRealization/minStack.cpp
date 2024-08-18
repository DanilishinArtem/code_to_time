#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    void push(int val) {
        if(stack_.empty()){
            min_.push(val);
            stack_.push(val);
        }else{
            if(val < min_.top()){
                min_.push(val);
                stack_.push(val);
            }else{
                min_.push(min_.top());
                stack_.push(val);
            }
        }
    }

    void pop() {
        stack_.pop();
        min_.pop();
    }

    int top() {
        return stack_.top();

    }

    int gitMin() {
        return min_.top();
    }

private:
    stack<int> stack_;
    stack<int> min_;
};


int main(){

    Solution obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout << obj.gitMin() << endl;
    obj.pop();
    cout << obj.top() << endl;
    cout << obj.gitMin() << endl;
    return 0;
}