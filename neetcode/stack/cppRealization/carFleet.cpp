#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        map<int, int> pair_;
        stack<int> stack_;
        int top;
        for(size_t i = 0; i < position.size(); i++){
            pair_[position[i]] = speed[i];
        }
        
        sort(pair_.begin(), pair_.end());

        for(size_t i = position.size() - 1; i > 0; i--){
            stack_.push((target - position[i]) / pair_[position[i]]);
            top = stack_.top();
            stack_.pop();
            if(stack_.size() >= 2 && top > stack_.top()){
                stack_.push(top);
            }
        }
        return stack_.size();
    }
};


int main(){
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    cout << Solution().carFleet(10, position, speed) << endl;
    return 0;
}


// class Solution:
//     @staticmethod
//     def carFleet(target: int, position: list[int], speed: list[int]) -> int:
//         pair = [[p,s] for p,s in zip(position, speed)]
//         stack = []
//         for p, s in sorted(pair)[::-1]:
//             stack.append((target - p) / s)
//             if len(stack) >= 2 and stack[-1] <= stack[-2]:
//                 stack.pop()
//         return len(stack)
 

// if __name__ == "__main__":
//     print(Solution.carFleet(10, [0,4,2], [2,1,3]))