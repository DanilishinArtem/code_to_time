#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result{};
        if(intervals.size() == 0){
            return result;
        }
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int lastEnd = result.back()[1];
            if(start <= lastEnd){
                result.back()[1] = max(lastEnd, end);
            }else{
                result.push_back({start, end});
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
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = s.merge(intervals);
    cout << "Input:" << endl;
    cout << "intervals = " << intervals << endl;
    cout << "Output:" << endl;
    cout << result << endl;
    return 0;
}