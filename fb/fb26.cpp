876. Middle of the Linked List


Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


884. Uncommon Words from Two Sentences


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> res;
        unordered_map<string, int> wordCnt;
        istringstream iss(A + " " + B);

        while (iss >> A)
         ++wordCnt[A];
        for (auto a : wordCnt) {
            if (a.second == 1) 
              res.push_back(a.first);
        }
        return res;
    }
};



856. Score of Parentheses

Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

Input: "()()"
Output: 2



class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0;
        stack<int> st;
        for (char c : S) {
            if (c == '(') {
                st.push(res);
                res = 0;
            } else {
                res = st.top() + max(res * 2, 1); 
                st.pop();
            }
        }
        return res;
    }
};



class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, cnt = 0, n = S.size();
        for (int i = 0; i < n; ++i) {
            (S[i] == '(') ? ++cnt : --cnt;
            if (S[i] == ')' && S[i - 1] == '(') res += (1 << cnt);
        }
        return res;
    }
};





1033. Moving Stones Until Consecutive

Three stones are on a number line at positions a, b, and c.

Each turn, you pick up a stone at an endpoint (ie., either the lowest or highest position stone), and move it to an unoccupied position between those endpoints.  Formally, let’s say the stones are currently at positions x, y, z with x < y < z.  You pick up the stone at either position x or position z, and move that stone to an integer position k, with x < k < z and k != y.

The game ends when you cannot make any more moves, ie. the stones are in consecutive positions.

When the game ends, what is the minimum and maximum number of moves that you could have made?  Return the answer as an length 2 array: answer = [minimum_moves, maximum_moves]



class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> nums{a, b, c};
        sort(nums.begin(), nums.end());
        int diff1 = nums[2] - nums[1], diff2 = nums[1] - nums[0];
        if (diff1 == 2 || diff2 == 2) return {1, nums[2] - nums[0] - 2};
        return {(diff1 > 1) + (diff2 > 1), nums[2] - nums[0] - 2};
    }
};


On an infinite number line, the position of the i-th stone is given by stones[i].  Call a stone an  endpoint stone  if it has the smallest or largest position.

Each turn, you pick up an endpoint stone and move it to an unoccupied position so that it is no longer an endpoint stone.

In particular, if the stones are at say, stones = [1,2,5], you cannot move the endpoint stone at position 5, since moving it to any position (such as 0, or 3) will still keep that stone as an endpoint stone.

The game ends when you cannot make any more moves, ie. the stones are in consecutive positions.

When the game ends, what is the minimum and maximum number of moves that you could have made?  Return the answer as an length 2 array: answer = [minimum_moves, maximum_moves]


Input: [7,4,9]
Output: [1,2]
Explanation:
We can move 4 -> 8 for one move to finish the game.
Or, we can move 9 -> 5, 4 -> 6 for two moves to finish the game.


class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size(), low = n, i = 0;
        for (int j = 0; j < n; ++j) {
            while (stones[j] - stones[i] + 1 > n) ++i;
            int already_store = j - i + 1;
            if (already_store == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
                low = min(low, 2);
            } else {
                low = min(low, n - already_store);
            }
        }
        return {low, max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2)};
    }
};


1110. Delete Nodes And Return Forest

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.


class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        helper(root, true, st, res);
        return res;
    }
    TreeNode* helper(TreeNode* node, bool is_root, unordered_set<int>& st, vector<TreeNode*>& res) {
        if (!node) return nullptr;
        bool deleted = st.count(node->val);
        if (is_root && !deleted) 
          res.push_back(node);
        node->left = helper(node->left, deleted, st, res);
        node->right = helper(node->right, deleted, st, res);
        return deleted ? nullptr : node;
    }
};


1209. Remove All Adjacent Duplicates in String II

class Solution {
 public:
  string removeDuplicates(const string& s, int k) {
    string ans;
    vector<pair<char, int>> stack;

    for (const char c : s)
      if (stack.empty() || stack.back().first != c)
        stack.emplace_back(c, 1);
      else if (++stack.back().second == k)  // Stack.back() == c
        stack.pop_back();

    for (const auto& [c, count] : stack)
      ans.append(count, c);

    return ans;
  }
};



1287. Element Appearing More Than 25% In Sorted Array
Given an integer array sorted in non-decreasing order, 
there is exactly one integer in the array that occurs more than 25% 
of the time, return that integer.


class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), t = n / 4;
        for (int i = 0; i < n - t; ++i) {
            if (arr[i] == arr[i + t]) return arr[i];
        }
        return -1;
    }
};



Given two binary search trees root1 and root2, return  a list containing
 all the integers from both trees sorted in ascending order.


class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        vector<int> ans1, ans2;
        dfs(root1, ans1);
        dfs(root2, ans2);

        int m = ans1.size(), n = ans2.size();
        vector<int> res(n + m, 0);

        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0) {
           if (ans1[i] >= ans2[j]){
              res[k--] = ans1[i];
              i--;
           }else {
              res[k--] = ans2[j]
              i--;
           }
        }

        while (i >= 0)
          res[k--] = ans1[i--];

        while (j >= 0)
          res[k--] = ans2[j--];

        return res;
    }
    void dfs(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        dfs(node->left, q);
        ans.push(node->val);
        dfs(node->right, q);
    }
};


/*
Find the Middle Index in Array



Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

 */

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size(), rsum = 0, lsum = 0;
        for (auto a:nums)
          rsum += a;

        for (int i = 0; i < n; ++i) {
          rsum -= nums[i];
          if (lsum == rsum)
            return i;
          lsum += nums[i];
        }
        return -1;
    }
};




/*Description
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Example 1:

Input: rating = [2,5,3,4,1]

Output: 3


*/



class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ans = 0;
        for (int j = 1; j < n - 1; ++j) {
            int ia = 0, ib = 0, ka = 0, kb = 0;
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j])
                    ++ia;
                else if (rating[i] > rating[j])
                    ++ib;
            }
            for (int k = j + 1; k < n; ++k) {
                if (rating[j] < rating[k])
                    ++ka;
                else if (rating[j] > rating[k])
                    ++kb;
            }
            ans += ia * ka + ib * kb;
        }
        return ans;
    }
};

