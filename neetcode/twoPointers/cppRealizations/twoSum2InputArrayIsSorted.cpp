#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size() - 1;
        while(index1 < index2){
            if(target - numbers[index1] < numbers[index2]){
                index2 -= 1;
            }else if(target - numbers[index1] > numbers[index2]){
                index1 += 1;
            }else if(target - numbers[index1] == numbers[index2]){
                return {index1 + 1, index2 + 1};
            }
        }
        return {-1, -1};
    }
};


int main(){
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = Solution().twoSum(numbers, target);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}