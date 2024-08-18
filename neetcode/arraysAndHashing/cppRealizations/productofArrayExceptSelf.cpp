#include <vector>
#include <iostream>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    int prod = 1;
    int zeros = 0;
    int index_zeros = -1;
    for(size_t i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            zeros++;
            index_zeros = i;
        }else{
            prod *= nums[i];
        }
    }

    if(zeros > 1){
        return result;
    }else if(zeros == 1){
        result[index_zeros] = prod;
    }else{
        for(size_t i = 0; i < nums.size(); i++){
            result[i] = prod / nums[i];
        }
        return result;
    }
    return result;
}

ostream& operator<<(ostream& out, const vector<int>& str){
    out << "[";
    for(size_t i = 0; i < str.size(); i++){
        if(i < str.size() - 1){
            out << str[i] << ",";
        }else{
            out << str[i];
        }
    }
    out << "]";
    return out;
}

int main(){
    vector<int> nums = {-1,1,0,-3,3};
    vector<int> result = productExceptSelf(nums);
    cout << "nums: " << nums << endl;
    cout << "result: " << result << endl;
    return 0;
}