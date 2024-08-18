#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack_ind;
        stack<int> stack_height;
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            int start = i;
            while(!stack_ind.empty() && stack_height.top() > heights[i]){
                int height = stack_height.top();
                int index = stack_ind.top();
                stack_ind.pop();
                stack_height.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            stack_ind.push(start);
            stack_height.push(heights[i]);
        }
        while(!stack_ind.empty()){
            for(int i = 0; i < stack_ind.size(); i++){
                int height = stack_height.top();
                int index = stack_ind.top();
                stack_ind.pop();
                stack_height.pop();
                maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - index));
            }
        }
        return maxArea;
    }
};


int main(){
    // vector<int> heights = {2, 1, 5, 6, 2, 3};
    vector<int> heights = {1, 1};
    cout << Solution().largestRectangleArea(heights) << endl;
    return 0;
}