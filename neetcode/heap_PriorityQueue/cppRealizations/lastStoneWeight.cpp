#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a > b){
                pq.push(a - b);
            }
        }
        if(pq.size() == 0){
            return 0;
        }
        return abs(pq.top());
    }
};


int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    int result = Solution().lastStoneWeight(stones);
    cout << result << endl;
    return 0;
}