/*tion for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0)
            return res;
        sort(intervals.begin(),intervals.end(),[&](const Interval& a,const Interval &b){return a.start < b.start ;});
        res.push_back(intervals[0]);
        for (int i=1;i<intervals.size();i++){
            if (res.back().end >= intervals[i].start)
                res.back().end = max(intervals[i].end,res.back().end);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res = intervals;
        auto it = res.begin();
        int overlap = 0;
        while(it != res.end()) {
            if(newInterval.end < it->start) break;
            else if(newInterval.start > it->end) {}   
            else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end   = max(newInterval.end, it->end);
                ++overlap;
            }
            ++it;
        }
        
        if(overlap != 0)
			 it = res.erase(it-overlap, it);
        res.insert(it, newInterval);
        return res;
    }
};

Meeting Room II

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for (auto a : intervals) {
            ++m[a.start];
            --m[a.end];
        }
        int rooms = 0, res = 0;
        for (auto it : m) {
            res = max(res, rooms += it.second);
        }
        return res;
    }
};

/*Given a set of n jobs with [start time, end time, cost] find a subset so that no 2 jobs overlap and the cost is maximum.
*/

d[i] = max(w(i) + d[p(i)], d[i-1]).



int getBestCombination(vector<Interval> intervals) {
    if (intervals.empty()) return 0;
   
    sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) {
        return i1.end < i2.end;
    });
   
    return findBestCombination(intervals);
}
int findBestCombination(vector<Interval>& intervals) {
    vector<int> dp(intervals.size() + 1);
   
    for (int i = 1; i <= intervals.size(); i++) {
        Interval currInt = intervals[i - 1];
        int pIndex = find(intervals, currInt.start, 0, (int)intervals.size() - 1);
        dp[i] = std::max(dp[pIndex+1] + currInt.cost, dp[i - 1]);
    }
   
    return dp[intervals.size()];
}
int find(vector<Interval>& intervals, int target, int left, int right) {
    if (left > right) {
        return right;
    } else {
        int mid = (left + right) / 2;
        if (intervals[mid].end == target) {
            return mid;
        } else if (intervals[mid].end > target) {
            return find(intervals, target, left, mid - 1);
        } else {
            return find(intervals, target, mid + 1, right);
        }
    }
}
