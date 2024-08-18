#include <map>
#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> hashMap;
    for(int i = 0; i < nums.size(); i++){
        int diff = target - nums[i];
        if (hashMap.find(diff) != hashMap.end()){
            return {hashMap[diff], i};
        } else {
            hashMap[nums[i]] = i;
        }
    }
    return {};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}