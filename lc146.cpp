//double linked list & hashmap, push to the front and pop from back
//list has splice function

class CacheNode{
public:
    int key;
    int val;
    CacheNode(int k, int v){
        key = k;
        val = v;
    }
};

class LRUCache{
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(CacheMap.find(key) == CacheMap.end()) return -1;
        auto it = CacheMap[key];
        CacheList.splice(CacheList.begin(), CacheList, it);
        return it->val;
    }
    
    void set(int key, int value) {
        if(CacheMap.find(key) == CacheMap.end()){
            if(CacheList.size() == size){
                CacheMap.erase(CacheList.back().key);
                CacheList.pop_back();
            }
            CacheList.push_front(CacheNode(key, value));
            CacheMap[key] = CacheList.begin();
        }
        else{
           auto it = CacheMap[key];
           it->val = value;
           CacheList.splice(CacheList.begin(), CacheList, it);
        }
    }

private:
    int size;
    list<CacheNode> CacheList;
    unordered_map<int, list<CacheNode>::iterator> CacheMap;
};
