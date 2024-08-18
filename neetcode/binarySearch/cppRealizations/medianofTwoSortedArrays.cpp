#include <vector>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;
// INT_MIN

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int total = nums1.size() + nums2.size();
        int half = total / 2;
        int l = 0, r = nums1.size() - 1;
        while(true){
            // i should be round below
            int i = floor(float(l + r) / 2); // A
            int j = half - i - 2; // B
            int Aleft = (i >= 0) ? nums1[i] : INT_MIN;
            int Aright = (i + 1 < nums1.size()) ? nums1[i + 1] : INT_MAX;
            int Bleft = (j >= 0) ? nums2[j] : INT_MIN;
            int Bright = (j + 1 < nums2.size()) ? nums2[j + 1] : INT_MAX;
            // partition is correct
            if(Aleft <= Bright && Bleft <= Aright){
                // odd
                if(total % 2){
                    return min(Aright, Bright);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }else if(Aleft > Bright){
                r = i - 1;
            }else{
                l = i + 1;
            }
        }
    }
};


int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    double result = Solution().findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}