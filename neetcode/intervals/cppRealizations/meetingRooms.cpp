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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        for(int i = 0; i < intervals.size() - 1; i++){
            if(intervals[i].end > intervals[i + 1].start){
                return false;
            }
        }
        return true;
    }
};



int main(){
    vector<Interval> intervals = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
    // vector<Interval> intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Output:" << endl;
    cout << Solution().canAttendMeetings(intervals) << endl;
    return 0;
}