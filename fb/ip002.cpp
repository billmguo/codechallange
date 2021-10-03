Given a binary array, find the maximum length of a contiguous subarray wit
 equal number of 0 and 1.

Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < n; ++i) {
            sum += (nums[i] == 1) ? 1 : -1;
            if (m.count(sum)) {
                res = max(res, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return res;
    }
};

/*
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

 

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
*/


class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty() || board[0].empty()) return {};
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q({{click[0], click[1]}});
        while (!q.empty()) {
            int row = q.front().first, col = q.front().second, cnt = 0; q.pop();
            vector<pair<int, int>> neighbors;
            if (board[row][col] == 'M') board[row][col] = 'X';
            else {
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) {
                        int x = row + i, y = col + j;
                        if (x < 0 || x >= m || y < 0 || y >= n) 
                        	continue;
                        if (board[x][y] == 'M') 
                        	++cnt;
                        else if (cnt == 0 && board[x][y] == 'E') 
                        	neighbors.push_back({x, y});
                    }
                }
            }
            if (cnt > 0) 
            	board[row][col] = cnt + '0';
            else {
                for (auto a : neighbors) {
                    board[a.first][a.second] = 'B';
                    q.push(a);
                }
            }
        }
        return board;
    }
};
/*
Given a grid where each entry is only 0 or 1, find the number of corner rectangles.

A corner rectangle is 4 distinct 1s on the grid that form an
 axis-aligned rectangle. Note that only the corners need to have the value 1. 
 Also, all four 1s used must be distinct.*/
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int cnt = 0;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] == 1 && grid[j][k] == 1) ++cnt;
                }
                res += cnt * (cnt - 1) / 2;
            }
        }
        return res;
    }
};
/* 

Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

0 < i, i + 1 < j, j + 1 < k < n - 1
Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.
*/

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if (nums.size() < 7) return false;
        int n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> s;
            for (int i = 1; i < j - 1; ++i) {
            	if (sums[i - 1] == sums[j - 1] - sums[i])
            		s.insert(sums[i - 1]);
            }
            for (int k = j + 1; k < n - 1; k++) {
            	int s3 = sums[k - 1] - sums[j], s4 = nums[n - 1] - sums[k];
            	if (s3 == s4 && s.count(s3)) return true;
            }
        }
        return false;
    }
};

/* 

Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two 
trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node
 values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        TreeNode *t = new TreeNode(t1->val + t2->val);
        t->left = mergeTrees(t1->left, t2->left);
        t->right = mergeTrees(t1->right, t2->right);
        return t;
    }
};


/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, 
down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop
at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start 
position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.*/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        dists[start[0]][start[1]] = 0;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            for (auto d : dirs) {
                int x = t.first, y = t.second, dist = dists[t.first][t.second];
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += d[0];
                    y += d[1];
                    ++dist;
                }
                x -= d[0];
                y -= d[1];
                --dist;
                if (dists[x][y] > dist) {
                    dists[x][y] = dist;
                    if (x != destination[0] || y != destination[1])
                        q.push({x, y});
                }
            }
        }
        int res = dists[destination[0]][destination[1]];
        return (res == INT_MAX) ? -1 : res;
    }
};

/*
interval intersection 
*/

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> v;
        int i=0,j=0;
        while(i<A.size() && j<B.size()){
            int l=max(A[i][0], B[j][0]);
            int u=min(A[i][1], B[j][1]);
            if(l<=u) v.push_back({l,u});
            if(A[i][1] < B[j][1])   i++;
            else j++;
        }
        return v;
    }
