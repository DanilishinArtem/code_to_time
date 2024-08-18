#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;


class Twitter {
public:
    Twitter() {
        count = 0;
        tweetMap = map<int, vector<pair<int, int>>>();
        followMap = map<int, set<int>>();
    }
    
    void postTweet(int userId, int tweetId) {
        if(tweetMap.find(userId) == tweetMap.end()){
            tweetMap[userId] = vector<pair<int, int>>();
        }
        tweetMap[userId].push_back({count, tweetId});
        count--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        // priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> minHeap;
        followMap[userId].insert(userId);
        for(auto followeeId : followMap[userId]){
            if(tweetMap.find(followeeId) != tweetMap.end()){
                int index = tweetMap[followeeId].size() - 1;
                int count = tweetMap[followeeId][index].first;
                int tweetId = tweetMap[followeeId][index].second;
                minHeap.push({count, tweetId, followeeId, index - 1});
            }
        }

        while(res.size() < 10 && !minHeap.empty()){
            auto [count, tweetId, followeeId, index] = minHeap.top();
            minHeap.pop();
            res.push_back(tweetId);
            if(index >= 0){
                count = tweetMap[followeeId][index].first;
                tweetId = tweetMap[followeeId][index].second;
                minHeap.push({count, tweetId, followeeId, index - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followMap.find(followerId) == followMap.end()){
            followMap[followerId] = set<int>();
        }
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap.find(followerId) == followMap.end()){
            return;
        }
        followMap[followerId].erase(followeeId);
    }
private:
    int count;
    map<int, vector<pair<int, int>>> tweetMap;
    map<int, set<int>> followMap;
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

int main(){
    Twitter* obj = new Twitter();
    obj->postTweet(1, 5);
    cout << obj->getNewsFeed(1) << endl;
    obj->follow(1, 2);
    obj->postTweet(2, 6);
    cout << obj->getNewsFeed(1) << endl;
    obj->unfollow(1, 2);
    cout << obj->getNewsFeed(1) << endl;


    return 0;
}