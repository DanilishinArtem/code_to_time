#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};


int main(){
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *temp = head;
    cout << "Input: " << endl;
    while(temp){
        cout << temp->val << endl;
        temp = temp->next;
    }
    head = Solution().reverseList(head);
    cout << "Solution: " << endl;
    while(head){
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}