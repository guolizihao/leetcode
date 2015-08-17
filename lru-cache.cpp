// https://leetcode.com/problems/lru-cache/

struct CacheNode {
    int key;
    int val;
    CacheNode(int k, int v): key(k), val(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        } else {
            cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
            cache_map[key] = cache_list.begin();
            return cache_map[key]->val;
        }
        
    }
    
    void set(int key, int value) {
        if (cache_map.find(key) == cache_map.end()) {
            if (cache_list.size() == size) {
                cache_map.erase(cache_list.back().key);
                cache_list.pop_back();
            }
            cache_list.push_front(CacheNode(key,value));
            cache_map[key] = cache_list.begin();
        } else {
            cache_map[key]->val = value;
            cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
            cache_map[key] = cache_list.begin();
        }
        
    }
private:
    list<CacheNode> cache_list;
    unordered_map<int, list<CacheNode>::iterator> cache_map;
    int size;
};
