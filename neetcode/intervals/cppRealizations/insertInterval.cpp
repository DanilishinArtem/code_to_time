#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        for(int i = 0; i < intervals.size(); i++){
            if(newInterval[1] < intervals[i][0]){
                result.push_back(newInterval);
                for(int j = i; j < intervals.size(); j++){
                    result.push_back(intervals[j]);
                }
                return result;
            }else if(newInterval[0] > intervals[i][1]){
                result.push_back(intervals[i]);
            }else{
                int min_ = min(newInterval[0], intervals[i][0]);
                int max_ = max(newInterval[1], intervals[i][1]);
                newInterval  = {min_, max_};
            }
        }
        result.push_back(newInterval);
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

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> result = s.insert(intervals, newInterval);
    cout << "Input:" << endl;
    cout << "intervals = " << intervals << endl;
    cout << "newInterval = " << newInterval << endl;
    cout << "Output:" << endl;
    cout << result << endl;
    return 0;
}
