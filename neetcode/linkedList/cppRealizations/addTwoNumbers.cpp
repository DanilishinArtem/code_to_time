#include <iostream>
#include <vector>
#include <cmath>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1->next || temp2->next){
            if(temp1->next == nullptr){
                temp1->next = new ListNode(0);
            }
            if(temp2->next == nullptr){
                temp2->next = new ListNode(0);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        ListNode* out = new ListNode();
        ListNode* cur = out;
        while(l1 && l2){
            if(cur->val + l1->val + l2->val >= 10){
                cur->next = new ListNode(floor(float(cur->val + l1->val + l2->val)/10));
                cur->val = (cur->val + l1->val + l2->val)%10;
            }else{
                if(l1->next || l2->next){
                    cur->next = new ListNode(0);
                }
                cur->val = cur->val + l1->val + l2->val;
            }
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        return out;
    }
};


int main(){

    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* out = Solution().addTwoNumbers(l1, l2);

    while(out){
        cout << out->val << endl;
        out = out->next;
    }

    return 0;
}