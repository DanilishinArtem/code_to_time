#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
 

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};


class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        for (Interval interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int res = 0, count = 0;
        int s = 0, e = 0;
        while(s < intervals.size()){
            if(starts[s] < ends[e]){
                count++;
                s++;
            }else{
                count--;
                e++;
            }
            res = max(res, count);
        }
        return res;
    }
};



int main(){
    vector<Interval> intervals = {Interval(0, 40), Interval(5, 10), Interval(15, 20)};
    // vector<Interval> intervals = {{0, 10}, {1, 3}, {2, 6}, {5, 8}, {7, 12}, {11, 15}, {13, 18}, {16, 20}, {19, 25}, {24, 30}};
    cout << "Output:" << endl;
    cout << Solution().minMeetingRooms(intervals) << endl;
    return 0;
}