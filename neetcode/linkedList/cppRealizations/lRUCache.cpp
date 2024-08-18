#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Node {
public:
    int key, val;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        left->next = right;
        right->prev = left;
        cap = capacity;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;
        prev->next = next->prev = node;
        node->next = next;
        node->prev = prev;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }else{
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        if(cache.size() > cap){
            // remove from the list and delete the LRU from the hashmap
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
private:
    int cap;
    map<int, Node*> cache;
    Node* left = new Node(0, 0);
    Node* right = new Node(0, 0);
};


int main(){

    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    obj->put(4, 4);

    return 0;
}