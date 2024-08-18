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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        while(lists.size() > 1){
            vector<ListNode*> mergedLists;
            for(int i = 0; i < lists.size(); i+=2){
                ListNode* l1 = lists[i];
                // ListNode* l2 = lists[i + 1];
                ListNode* l2;
                if(i + 1 < lists.size()){
                    l2 = lists[i + 1];
                }else{
                    l2 = nullptr;
                }
                mergedLists.push_back(mergeLists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }

    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;
        return dummy->next;
    }
};


int main() {
    vector<ListNode*> input = {new ListNode(1, new ListNode(4, new ListNode(5))), new ListNode(1, new ListNode(3, new ListNode(4))), new ListNode(2, new ListNode(6))};
    ListNode* out = Solution().mergeKLists(input);
    while(out){
        cout << out->val << endl;
        out = out->next;
    }
    return 0;
}