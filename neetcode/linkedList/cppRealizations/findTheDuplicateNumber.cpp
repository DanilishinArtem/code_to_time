#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        int slow2 = 0;
        while(true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow == slow2){
                return slow;
            }
        }
    }
};


int main(){
    vector<int> nums = {1,3,4,2,2};
    cout << Solution().findDuplicate(nums) << endl;
    return 0;
}