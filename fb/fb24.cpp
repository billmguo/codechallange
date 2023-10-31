Problem
You are given a 0-indexed array of positive integers tasks, representing 
    tasks that need to be completed in order, where tasks[i] represents the type of the ith task.

You are also given a positive integer space, which represents the minimum 
number of days that must pass after the completion of a task before another task of the same type can be performed.

Each day, until all tasks have been completed, you must either:

Complete the next task from tasks, or

Take a break.

Return** the minimum number of days needed to complete all tasks**.
class Solution {
 public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, long long> taskToNextAvailable;
    long long ans = 0;

    for (const int task : tasks) {
      ans = max(ans + 1, taskToNextAvailable[task]);
      taskToNextAvailable[task] = ans + space + 1;
    }

    return ans;
  }
};



class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0.0;
        double res = DBL_MAX;
        unordered_map<string, vector<vector<int>>> m;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long dist = getLength(points[i], points[j]);
                double centerX = (points[i][0] + points[j][0]) / 2.0;
                double centerY = (points[i][1] + points[j][1]) / 2.0;
                string key = to_string(dist) + "_" + to_string(centerX) + "_" + to_string(centerY);
                m[key].push_back({i, j});
            }
        }
        for (auto &a : m) {
            vector<vector<int>> vec = a.second;
            if (vec.size() < 2) continue;
            for (int i = 0; i < vec.size(); ++i) {
                for (int j = i + 1; j < vec.size(); ++j) {
                    int p1 = vec[i][0], p2 = vec[j][0], p3 = vec[j][1];
                    double len1 = sqrt(getLength(points[p1], points[p2]));
                    double len2 = sqrt(getLength(points[p1], points[p3]));
                    res = min(res, len1 * len2);
                }
            }
        }
        return res == DBL_MAX ? 0.0 : res;
    }
    long getLength(vector<int>& pt1, vector<int>& pt2) {
        return (pt1[0] - pt2[0]) * (pt1[0] - pt2[0]) + (pt1[1] - pt2[1]) * (pt1[1] - pt2[1]);
    }
};
