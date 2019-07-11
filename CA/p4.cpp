[LeetCode] Employee Free Time 职员的空闲时间
 

We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
 

Example 2:

Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
'
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> res;
        map<int, int> m;
        int cnt = 0;
        for (auto employee : schedule) {
            for (Interval i : employee) {
                ++m[i.start];
                --m[i.end];
            }
        }
        for (auto a : m) {
            cnt += a.second;
            if (!cnt) res.push_back(Interval(a.first, 0));
            if (cnt && !res.empty() && !res.back().end) res.back().end = a.first;
        }
        if (!res.empty()) res.pop_back();
        return res;
    }
};
