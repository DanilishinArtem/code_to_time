#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(target > nums[nums.size() - 1] || target < nums[0]){
            return -1;
        }
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return -1;
    }
};



int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << Solution().search(nums, target) << endl;
    return 0;
}