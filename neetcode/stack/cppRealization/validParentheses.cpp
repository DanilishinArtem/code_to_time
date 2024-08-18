#include <iostream>
#include <stack>
#include <map>

using namespace std;


class Solustion {
public:
    static bool isValid(string& s){
        stack<char> stack;
        map<char, char> closeToOpen = {{')', '('}, {']', '['}, {'}', '{'}};
        for(char c : s){
            if(closeToOpen.find(c) != closeToOpen.end()){
                if(!stack.empty() && stack.top() == closeToOpen[c]){
                    stack.pop();
                }else{
                    return false;
                }
            }else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
};


int main(){
    string s = "([{}])";
    if(Solustion::isValid(s) == true){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
    return 0;
}