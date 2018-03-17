Intersection of Two Sorted Intervals

vector<Interval> intersection(vector<Interval>& lhs, vector<Interval>& rhs) {
    vector<Interval> res;
   
    map<int, int> m;
    for (auto& a : lhs) {
        m[a.start]++;
        m[a.end]--;
    }

    for (auto& a : rhs) {
        m[a.start]++;
        m[a.end]--;
    }

    Interval pivot;
    int cur = 0;
    for (auto& a : m) {
        cur +=  a.second;
        if (cur == 2) {
            pivot.start = a.first;
        } else if (pivot.start != pivot.end) {
            pivot.end = a.first;
            res.push_back(pivot);
            pivot.reset();
        }
    }
    return res;
};
