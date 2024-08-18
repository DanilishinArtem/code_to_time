#include <set>
#include <vector>
#include <iostream>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    set<int> hashset;
    for(const int& item : nums){
        if(hashset.find(item) != hashset.end()){
            return true;
        }else{
            hashset.insert(item);
        }
    }
    return false;
}

int main(){
    vector<int> nums = {1,2,3,1};
    cout << containsDuplicate(nums) << endl;
    return 0;
}