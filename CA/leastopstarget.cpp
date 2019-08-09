class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
      unordered_set<int> s;
      q.emplace(0, target);
      while (!q.empty()) {
        const int c = q.top().first;
        const int t = q.top().second;
        q.pop();
        if (t == 0) return c - 1;
        if (s.count(t)) continue;
        s.insert(t);
        int n = log(t) / log(x);
        int l = t - pow(x, n);        
        q.emplace(c + (n == 0 ? 2 : n), l);
        int r = pow(x, n + 1) - t;        
        q.emplace(c + n + 1, r);
      }
      return -1;
    }
};
