#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> minHeap;
        for(int i = 0; i < points.size(); i++){
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            minHeap.push({-dist, points[i][0], points[i][1]});
        }

        vector<vector<int>> result;
        for(int i = 0; i < k; i++){
            result.push_back({minHeap.top()[1], minHeap.top()[2]});
            minHeap.pop();
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
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;
    cout << "Input:" << endl;
    cout << "points = " << points << endl;
    vector<vector<int>> result = Solution().kClosest(points, k);
    cout << "kClosest: " << result << endl;
    return 0;
}