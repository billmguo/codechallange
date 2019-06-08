vector<long> pre(10, 1), cur(10, 0);

Base case: when N is 1, the knight will take zero hops from its current digit

dp[1][0:9] = 1


Recursive case: observe the overlapping subproblems and optimal substructure. The current i-th hop for 
each keypad digit can be found from the previous i - 1 hop for each keypad digit which can reach the 
current keypad digit from a single hop. Therefore calculate the current i-th hop for
each keypad destination digit (dst) as the sum of all keypad source digits (src) i-th-minus-1 hop solutions.


dp[i][dst] = dp[i - 1][src] (for src in the direction)


class Solution {
public:
    int knightDialer(int N) {
        const long long mod = 1e9 + 7;
        const vector<vector<int>> g = {{4,6}, {6,8}, {7,9}, {4,8}, {3,9,0},
            {}, {1,7,0}, {2,6}, {1,3}, {2,4}};
        vector<long long> pre(10,1), cur(10,0);
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < 10; j++) {
                cur[j] = 0;
                for (auto n:g[j]) cur[j] += pre[n];
                cur[j] %= mod;
            }
            swap(cur, pre);
        }
        return accumulate(pre.begin(), pre.end(), 0LL) % mod;
    }
};
