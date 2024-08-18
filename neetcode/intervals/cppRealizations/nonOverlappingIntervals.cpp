#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int result = 0;
        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start >= prevEnd){
                prevEnd = end;
            }else{
                result += 1;
                prevEnd = min(prevEnd, end);
            }
        }
        return result;
    }
};


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


ostream& operator<<(ostream& out, const vector<vector<int>>& str){
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
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution s;
    cout << "Input" << endl;
    cout << "intervals = " << intervals << endl;
    cout << "Output:" << endl;
    int result = s.eraseOverlapIntervals(intervals);
    cout << result << endl;
    return 0;
}