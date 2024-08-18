#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;


class MedianFinder {
public:
    MedianFinder() {
        small = priority_queue<int>();
        large = priority_queue<int>();
    }
    
    void addNum(int num) {
        small.push(num);
        // make sure that every num "small" is <= every num "large"
        if(small.size() > 0 && large.size() > 0 && small.top() > -large.top()){
            int val = small.top();
            small.pop();
            large.push(-val);
        }
        // uneven size?
        if(small.size() > large.size() + 1){
            int val = small.top();
            small.pop();
            large.push(-val);
        }
        if(large.size() > small.size() + 1){
            int val = -large.top();
            large.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()){
            return small.top();
        }
        if(large.size() > small.size()){
            return -large.top();
        }
        return (small.top() - large.top()) / 2.0;
    }
private:
    priority_queue<int> small;
    priority_queue<int> large;
};


int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(-1);
    cout << obj->findMedian() << endl;
    obj->addNum(-2);
    cout << obj->findMedian() << endl;
    obj->addNum(-3);
    cout << obj->findMedian() << endl;

    // vector<int> nums = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    // // priority_queue<int, vector<int>, greater<int>> small = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
    // priority_queue small = priority_queue(nums.begin(), nums.end());

    // for (int i = 0; i < nums.size(); i++) {
    //     cout << small.top() << endl;
    //     small.pop();
    // }
    return 0;
}