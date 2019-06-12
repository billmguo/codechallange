class AllOne {
private:
    map<int,set<string>> reverse;
    unordered_map<string,int> table;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (table.count(key)) {
            reverse[table[key]].erase(key);
            if (reverse[table[key]].empty())
                reverse.erase(table[key]);
            table[key]++;
            reverse[table[key]].insert(key);
        } else {
            table[key] = 1;
            reverse[1].insert(key);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (table.count(key)) {
            reverse[table[key]].erase(key);
            if (reverse[table[key]].empty())
                reverse.erase(table[key]);
            if (table[key] == 1)
                table.erase(key);
            else{
                --table[key];
                reverse[table[key]].insert(key);
            }
        } 
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        auto last = reverse.rbegin();
        if (last == reverse.rend())
            return "";
        else
            return *(last->second.rbegin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        auto first = reverse.begin();
        if(first == reverse.end()){
            return "";
        }
        else{
            return *(first->second.begin());
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
