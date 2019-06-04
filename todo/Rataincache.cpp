
     template K, T;
     map<K, T> cache;
     map<long, set<k>> rankc;
     ds<K, T> ds;
     int msize;
     
     RetainBestCache(DataSource<K,T> ds, int size) {
        cache.clear();
        rankc.clear();
        ds = ds;
        msize = size;
     }    

     T get(K key) {
        if (cache.count(key))
          return cache[key];
        return getfromds(key);
     }

     T getfromds(K key) {
        if (cache.size() >= m.size()) {
            evictElement();
        }
        T object = ds.get(key);
        cache.put({K, object});
        long rank = ds.getrank();
        rankc[rank].push_back(key);
        return object;
     }

     void evictElement() {
        auto entry = rankc.begin();
        auto k = entry->second.back();
        cache.erase(k);
        if (entry->second.empty())
            rankc.erase(entry->first);
     }
