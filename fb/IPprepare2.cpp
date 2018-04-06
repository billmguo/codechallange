Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

class Solution {
public:
    string toHex(int num) {
        string t="0123456789abcdef";
        string res = "";
        int cnt = 0;
        while (num != 0 && cnt++ < 8) {
            res = t[num&0xf] + res;
            num >>= 4;
        }
        return res.empty()?"0":res;
    }
};



typedef pair<int,int> pp;

int getdistance(pp &a, pp &b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx*dx + dy*dy;
}
int getpairs(vector<pp> points) {
    int res;
    if (points.empty())
        return res;
    for (int i = 0; i < points.size();i++) {
        unordered_map<int,int> m;
        for (int j = 0; j < points.size(); j++) {
            if ( i != j ) {
                int d = getdistance(points[i], points[j]);
                m[d]++;
            }
        }
        for (auto a:m) {
            res += a.second * (a.second - 1);
        }
    }
    return res;
}


Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).


bool isconv(vector<pp> & point) {
    long long n = point.size(), pre = 0 , cur = 0;
    for (int i = 0; i < point.size(); i++) {
        int dx1 = point[(i + 1) % n].first - point[i].first;
        int dy1 = point[(i + 1) % n].second - point[i].second;
        int dx2 = point[(i + 2) % n].first - point[i].first;
        int dy2 = point[(i + 2) % n].second - point[i].second;
        cur = dx1 * dy2 - dy1*dx2;
        if (cur != 0) {
            if (cur * pre < 0)
                return false;
            else
                pre = cur;
        }
    }
    return true;
}


Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True


    bool validsquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s{d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4)};
        return !s.count(0) && s.size() == 2;
    }
    int d(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }


maxroom

int findmaxarrow(vector<pp> points) {
    if (points.empty())
        return 0;
    map<int, int> m;
    for (auto a:points) {
        m[a.first]++;
        m[a.second]--;
    }
    int res = 0, cnt = 0;
    for (auto a:m) {
        res = max(res, cnt + a.second);
    }
    return res;
}


Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.



 double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> sums = nums;
    for (int i = 1; i < n; i++) {
        sums[i] = sums[i - 1] + nums[i];
    }
    double res = (double) sums[k - 1]/k;
    for (int i = k; i < n; i++) {
        double t = (double) (sums[i]);
        if ( t > res * (i + 1))
            res = t / (i + 1);
        for (int j = i - k; i >= 0; i--) {
            t = sums[i] - sums[j];
            if ( t > res * (i - j))
                res = t / (i - j);
        }
    }
    return res;
}      


double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> sums(n + 1, 0);
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (left + 1e-5 < right) {
            double mins = 0, mid = left + (right - left) / 2;
            bool check = false;
            for (int i = 1; i <= n; i++) {
                sums[i] = sums[i - 1] + nums[i - 1] - mid;
                if (i >= k)
                    mins = min(mins, sums[i-k]);
                if (i >= k && sums[i] > mins) {
                    check = true;
                    break;
                }   
            }
            if (check)
                left = mid;
            else
                right = mid;
        }
        return left;
    }

A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7
    
int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        int n = A.size();
        vector<int> dp(n, 0);
        for (int i = 2 ; i < n; i++) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2])
                dp[i] = dp[i-1] + 1;
            res += dp[i];    
        }
        return res;
    }
    
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.

A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.

The function should return the number of arithmetic subsequence slices in the array A.

The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.

   int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size();
        vector<unordered_map<int, int>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)A[i] - (long long)A[j];
                if (diff > INT_MAX || diff < INT_MIN) continue;
                int d = (int)diff;
                if (!dp[i].count(d)) dp[i][d] = 0;
                ++dp[i][d];
                if (dp[j].count(d)) {
                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
