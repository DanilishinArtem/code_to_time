#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        int pivot = nums[right];
        int p = left;
        for(int i = left; i < right; i++){
            if(nums[i] < pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[right]);
        if(p + 1 == k){
            return nums[p];
        }else if(p + 1 < k){
            return quickSelect(nums, p + 1, right, k);
        }else{
            return quickSelect(nums, left, p - 1, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k + 1;
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};


int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << Solution().findKthLargest(nums, k) << endl;
    return 0;
}