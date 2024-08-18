#include <vector>
#include <map>
#include <iostream>

using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> count;
    vector<vector<int>> frequency(nums.size()+1);
    for(const int& item : nums){
        count[item] += 1;
    }
    for(pair<int, int> item : count){
        frequency[item.second].push_back(item.first);
    }
    vector<int> result{};
    for(int i = nums.size(); i > 0; i--){
        if(result.size() == k){
            break;
        }
        for(const int& item : frequency[i]){
            result.push_back(item);
        }
    }
    return result;
}

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> result;
    result = topKFrequent(nums, 2);
    for(const int& item : result){
        cout << item << endl;
    }
    return 0;
}