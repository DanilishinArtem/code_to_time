#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count = vector<int>(26, 0);
        for(char c : tasks){
            count[c - 'A']++;
        }
        priority_queue<int> maxHeap;
        for(int i = 0; i < 26; i++){
            if(count[i] > 0){
                maxHeap.push(count[i]);
            }
        }

        int time = 0;
        deque<pair<int, int>> q; // time, idleTime
        while(!maxHeap.empty() || !q.empty()){
            time++;
            if(!maxHeap.empty()){
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if(cnt > 0){
                    q.push_back({cnt, time + n});
                }
            }
            if(!q.empty() && q.front().second == time){
                pair<int, int> temp = q.front();
                q.pop_front();
                maxHeap.push(temp.first);
            }
        }
        return time;
    }
};


int main(){
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << Solution().leastInterval(tasks, n) << endl;
    return 0;
}