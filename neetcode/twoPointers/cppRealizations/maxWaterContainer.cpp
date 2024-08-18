#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        while(l < r){
            res = max(res, min(height[l], height[r]) * (r - l));
            if(height[l] < height[r]){
                l += 1;
            }else{
                r -= 1;
            }
        }
        return res;
    }
};


int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(height) << endl;
    return 0;
}