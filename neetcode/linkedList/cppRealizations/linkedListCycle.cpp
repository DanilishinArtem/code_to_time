#include <iostream>
#include <vector>
#include <climits>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        while(head){
            if(head->val == INT_MAX){
                return true;
            }
            head->val = INT_MAX;
            head = head->next;
        }
        return false;
    }
};


int main(){
    vector<ListNode*> input = {new ListNode(3), new ListNode(2), new ListNode(0), new ListNode(-4)};
    input[0]->next = input[1];
    input[1]->next = input[2];
    input[2]->next = input[3];
    input[3]->next = input[1];
    
    
    cout << Solution().hasCycle(input[0]) << endl;
    return 0;
}