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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while(n > 0){
            right = right->next;
            n--;
        }

        while(right != nullptr){
            right = right->next;
            left = left->next;
        }

        // delete
        left->next = left->next->next;
        return dummy->next;
    }
};


int main(){
    ListNode *list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    list = Solution().removeNthFromEnd(list, 2);
    while(list){
        cout << list->val << endl;
        list = list->next;
    }
    return 0;
}