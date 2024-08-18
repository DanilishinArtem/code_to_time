#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while(l < r){
            if(leftMax < rightMax){
                l += 1;
                leftMax = max(leftMax, height[l]);
                res += max(0, leftMax - height[l]);
            }else{
                r -= 1;
                rightMax = max(rightMax, height[r]);
                res += max(0, rightMax - height[r]);
            }
        }
        return res;
    }
};


int main(){
    vector<int> height = {4,2,0,3,2,5};
    cout << Solution().trap(height) << endl;
    return 0;
}