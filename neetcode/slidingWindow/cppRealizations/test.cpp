#include <iostream>
#include <map>

using namespace std;


int main(){
    map<char, int> count;
    count['a'] = 1;
    count['a'] = count['a'] + 1;
    count['b'] = count['b'] + 1;

    for(auto item : count){
        cout << item.first << " " << item.second << endl;
    }
}