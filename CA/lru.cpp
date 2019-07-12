class LRUCache {
private:
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (!m.count(key))
            return -1;
        movetohead(key);
        return m[key]->second;
    }
    
    void put(int key, int value) {
       if (m.count(key)) {
           m[key]->second = value;
           movetohead(key);
       } else {
          if (cache.size() >= size) {
                m.erase(cache.back().first);
                cache.pop_back();
          }  
          cache.push_front({key, value});
          m[key] = cache.begin();
       }
        
    }
    void movetohead(int key) {
        auto it = m[key];
        cache.push_front(*it);
        cache.erase(it);
        m[key] = cache.begin();
    }
};
