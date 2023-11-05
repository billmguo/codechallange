/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.*/

Your algorithm should run in O( n ) complexity.
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> seen{nums.begin(), nums.end()};

    for (int num : nums) {
      // Num is the start of a sequence
      if (seen.count(num - 1))
        continue;
      int length = 1;
      while (seen.count(++num))
        ++length;
      ans = max(ans, length);
    }

    return ans;
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

Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).


The object of this problem is to find the number of monotone subsequences that have length 3 of the given array rating.
 Since the length of rating does not exceed 200, this problem can be solved by brute force. A solution of dynamic
  programming also exists.

Consider two cases, where each subsequence is monotonically increasing or monotonically decreasing. 
First consider the monotonically increasing case. Create an array dp of length n, wnere dp[i] represents 
the number of elements in subarray rating[0..i - 1] that are less than rating[i]. Loop over i from 1 to n - 1. For each i,
 loop over j from i - 1 to 0. If rating[i] > rating[j], then increase dp[i] by 1, and at the same time, if dp[j] > 0,
  then there exist several elements before j that are less than rating[j], so add dp[j] to the number of teams. After the loop, 
  the number of teams that are monotically increasing can be obtained.

For the monotonically decrease case, the logic is almost the same except that rating[i] < rating[j]
 is used instead of rating[i] > rating[j].
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


809. Expressive Words

Sometimes people repeat letters to represent extra feeling, such as “hello” -> “heeellooo”, “hi” -> “hiiii”.  Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or more, so “e” and “o” would be extended in the first example, and “i” would be extended in the second example.  As another example, the groups of “abbcccaaaa” would be “a”, “bb”, “ccc”, and “aaaa”; and “ccc” and “aaaa” are the extended groups of that string.

class Solution {
 public:
  int expressiveWords(string s, vector<string>& words) {
    int ans = 0;

    for (const string& word : words)
      if (isStretchy(s, word))
        ++ans;

    return ans;
  }

 private:
  bool isStretchy(const string& s, const string& word) {
    const int n = s.length();
    const int m = word.length();

    int j = 0;
    for (int i = 0; i < n; ++i)
      if (j < m && s[i] == word[j])
        ++j;
      else if (i > 1 && s[i] == s[i - 1] && s[i - 1] == s[i - 2])
        continue;
      else if (i > 0 && i + 1 < n && s[i - 1] == s[i] && s[i] == s[i + 1])
        continue;
      else
        return false;

    return j == m;
  }
};
 


742 Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

Here,  nearest  to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a  leaf  if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> back;
        TreeNode *kNode = find(root, k, back);
        queue<TreeNode*> q{{kNode}};
        unordered_set<TreeNode*> visited{{kNode}};
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (!t->left && !t->right) return t->val;
            if (t->left && !visited.count(t->left)) {
                visited.insert(t->left);
                q.push(t->left);
            }
            if (t->right && !visited.count(t->right)) {
                visited.insert(t->right);
                q.push(t->right);
            }
            if (back.count(t) && !visited.count(back[t])) {
                visited.insert(back[t]);
                q.push(back[t]);
            }
        }
        return -1;
    }
    TreeNode* find(TreeNode* node, int k, unordered_map<TreeNode*, TreeNode*>& back) {
        if (node->val == k) return node;
        if (node->left) {
            back[node->left] = node;
            TreeNode *left = find(node->left, k, back);
            if (left) return left;
        }
        if (node->right) {
            back[node->right] = node;
            TreeNode *right = find(node->right, k, back);
            if (right) return right;
        }
        return NULL;
    }
};


714. Best Time to Buy and Sell Stock with Transaction Fee

sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);

hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> sold(prices.size(), 0), hold = sold;
        hold[0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
        }
        return sold.back();
    }
};
