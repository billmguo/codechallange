
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int m[26];
        for (int i = 0; i < 26; i++)
            m[order[i] - 'a'] = i;
        for (auto &a:words) {
            for (auto &c:a) {
                c = m[c -'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};


class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int preTime = 0, idx = 0, time = 0;
        char type[10];
        for (string log : logs) {
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &time);
            if (type[0] == 's') {
                if (!st.empty()) {
                    res[st.top()] += time - preTime;
                }
                st.push(idx);
            } else {
                res[st.top()] += ++time - preTime;
                st.pop();
            }
            preTime = time;
        }
        return res;
    }
};


class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        bool xwin = false, owin = false;
        vector<int> row(3), col(3);
        int diag = 0, antidiag = 0, turns = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') {
                    ++row[i]; ++col[j]; ++turns;
                    if (i == j) ++diag;
                    if (i + j == 2) ++antidiag;
                } else if (board[i][j] == 'O') {
                    --row[i]; --col[j]; --turns;
                    if (i == j) --diag;
                    if (i + j == 2) --antidiag;
                }
            }
        }
        xwin = row[0] == 3 || row[1] == 3 || row[2] == 3 ||
               col[0] == 3 || col[1] == 3 || col[2] == 3 ||
               diag == 3 || antidiag == 3;
        owin = row[0] == -3 || row[1] == -3 || row[2] == -3 ||
               col[0] == -3 || col[1] == -3 || col[2] == -3 ||
               diag == -3 || antidiag == -3;
        if ((xwin && turns == 0) || (owin && turns == 1)) return false;
        return (turns == 0 || turns == 1) && (!xwin || !owin);
    }
};


class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> m;
        helper(root, m, res);
        return res;
    }
    string helper(TreeNode* node, unordered_map<string, int>& m, vector<TreeNode*>& res) {
        if (!node)
            return "#";
        string str = to_string(node->val) + "," + helper(node->left,m, res) + "," + helper(node->right, m, res);
        if (m[start] == 1)
            res.push_back(node);
        ++m[str];
        return str;
    }
};
