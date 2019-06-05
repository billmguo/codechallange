all one 

     map<int,set<string>> reverse;
     unordered_map<string,int> table;

LFU cache
 int cap, minFreq;
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> iter;

LRU cache
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
