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
    void reorderList(ListNode* head) {
        // find the middle of the list
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the second half of the list
        ListNode *second = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;
        while(second){
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }
        // merge the two lists
        ListNode *first = head;
        second = prev;
        while(second){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};


int main(){
    ListNode *list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    Solution().reorderList(list);
    while(list){
        cout << list->val << endl;
        list = list->next;
    }
    return 0;
}