#include <iostream>
#include <vector>
#include <map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> copyMap;
        Node* curr = head;
        while(curr != nullptr){
            copyMap[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr != nullptr){
            copyMap[curr]->next = copyMap[curr->next];
            copyMap[curr]->random = copyMap[curr->random];
            curr = curr->next;
        }
        return copyMap[head];
    }
};

void printResult(Node* start){
    while(start != nullptr){
        if(start->random != nullptr){
            cout << start->val << " " << start->random->val << endl;
        }else{
            cout << start->val << " " << "NULL" << endl;
        }
        start = start->next;
    }
}

int main(){
    vector<Node*> temp = {new Node(7), new Node(13), new Node(11), new Node(10), new Node(1)};
    temp[0]->next = temp[1];
    temp[1]->next = temp[2];
    temp[2]->next = temp[3];
    temp[3]->next = temp[4];
    temp[0]->random = nullptr;
    temp[1]->random = temp[0];
    temp[2]->random = temp[4];
    temp[3]->random = temp[2];
    temp[4]->random = temp[0];
    cout << "Input: " << endl;
    Node* start = temp[0];
    printResult(start);

    cout << "Solution: " << endl;
    Node* copyHead = Solution().copyRandomList(temp[0]);
    printResult(copyHead);
    return 0;
}