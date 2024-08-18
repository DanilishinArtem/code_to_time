#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> q;
        int r = 0;
        int l = 0;
        while(r < nums.size()){
            // pop smaller values from the q
            while(!q.empty() && nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);
            if(l > q.front()){
                q.pop_front();
            }
            if(r + 1 >= k){
                result.push_back(nums[q.front()]);
                l += 1;
            }
            r += 1;
        }
        return result;
    }
};


int main(){
    vector<int> nums = {1,2,1,0,4,2,6};
    int k = 3;
    vector<int> result = Solution().maxSlidingWindow(nums, k);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}