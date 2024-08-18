#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


class TimeMap {
public:
    TimeMap() {
        map<string, vector<pair<string, int>>> store;
    }
    
    void set(string key, string value, int timestamp) {
        if(store.find(key) == store.end()){
            store[key] = vector<pair<string, int>>();
        }
        store[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        string result = "";
        if(store.find(key) == store.end()){
            return result;
        }
        vector<pair<string, int>> values = store[key];
        int l = 0, r = values.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(values[mid].second <= timestamp){
                result = values[mid].first;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return result;
    }
private:
    map<string, vector<pair<string, int>>> store;
};


int main(){
    TimeMap* obj = new TimeMap();
    vector<string> out;
    
    obj->set("foo", "bar", 1);
    out.push_back(obj->get("foo", 1));
    out.push_back(obj->get("foo", 3));
    obj->set("foo", "bar2", 4);
    out.push_back(obj->get("foo", 4));
    out.push_back(obj->get("foo", 5));
    delete obj;
    for(auto item : out){
        cout << item << endl;
    }
    return 0;
}