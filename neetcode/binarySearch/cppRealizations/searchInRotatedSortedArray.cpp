#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[l] <= nums[mid]){
                if(target >= nums[l] && target < nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }else{
                if(target <= nums[r] && target > nums[mid]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};


int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << Solution().search(nums, target) << endl;
    return 0;
}