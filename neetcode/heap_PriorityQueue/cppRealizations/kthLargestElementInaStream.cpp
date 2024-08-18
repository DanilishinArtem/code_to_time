#include <vector>
#include <iostream>
#include <queue>
using namespace std;


class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(auto num : nums){
            minHeap.push(num);
        }
        while(minHeap.size() > k_){
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k_){
            minHeap.pop();
        }
        return minHeap.top();
    }
private:
    int k_;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};


int main(){
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(3, nums);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
    return 0;
}