#include <iostream>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;
        while(true){
            ListNode* kth = getKth(groupPrev, k);
            if(kth == nullptr){
                break;
            }
            ListNode* groupNext = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;
            while(curr != groupNext){
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }
        return dummy->next;
    }

    ListNode* getKth(ListNode* curr, int k) {
        while(curr != nullptr && k > 0){
            curr = curr->next;
            k -= 1;
        }
        return curr;
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
    head = Solution().reverseKGroup(head, 3);
    cout << "Solution: " << endl;
    while(head){
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}