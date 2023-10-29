1762

Buildings With an Ocean View
Description
There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

Example 1:

Input: heights = [4,2,3,1]

Output: [0,2,3]

class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    vector<int> stack;

    for (int i = 0; i < heights.size(); ++i) {
      while (!stack.empty() && heights[stack.back()] <= heights[i])
        stack.pop_back();
      stack.push_back(i);
    }

    return stack;
  }
};
1038 Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

As a reminder, a  binary search tree  is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int cur = 0;
        helper(root, cur);
        return root;
    }
    void helper(TreeNode*& node, int& cur) {
        if (!node) return;
        helper(node->right, cur);
        node->val += cur;
        cur = node->val;
        helper(node->left, cur);
    }
};
2025
You are given a 0-indexed integer array nums of length n. The number of ways to partition nums is the
number of pivot indices that satisfy both conditions:

1 <= pivot < n
nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]
You are also given an integer k. You can choose to change the value of one element of nums to k, or to leave the array unchanged.

Return the maximum possible number of ways to partition nums to satisfy both conditions after changing at most one element
int waytopartition(vector<int> &nums, int k) {
	int n = nums.size();
	long sum = accumulate(begin(nums),end(nums), 0L);
	int prefix = 0;
	unordered_map<long, int> l, r;
	for (int i = 1; i < n; ++i) {
		prefix += nums[i-1];
		long suffix = sum - prefix;
		++r[prefix - suffix];
	}
	int ans = rm[0];
	prefix = 0;
	for (int i = 0; i < n; ++i) {
		prefix += nums[i];
		int d = k - nuums[i];
		ans  = max(ans, l[d] + r[-d]);
		long suffix = sum - nums;
		diff = prefix - suffix;
		--r[diff];
		++l[diff];
	}
}

TreeDiameter Description
Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.

The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between nodes u and v. Each node has labels in the set {0, 1, ..., edges.length}.



class Solution {
 public:
  int treeDiameter(vector<vector<int>>& edges) {
    const int n = edges.size();
    int ans = 0;
    vector<vector<int>> tree(n + 1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    maxDepth(tree, 0, -1, ans);
    return ans;
  }

 private:
  int maxDepth(const vector<vector<int>>& tree, int u, int parent, int& ans) {
    int maxDepth1 = 0;   // The max depth
    int maxDepth2 = -1;  // The 2nd max depth

    for (const int v : tree[u]) {
      if (v == parent)
        continue;
      const int depth = maxDepth(tree, v, u, ans);
      if (depth > maxDepth1) {
        maxDepth2 = maxDepth1;
        maxDepth1 = depth;
      } else if (depth > maxDepth2) {
        maxDepth2 = depth;
      }
    }

    ans = max(ans, maxDepth1 + maxDepth2);
    return 1 + maxDepth1;
  }
};

1361 You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.
 
class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                               vector<int>& rightChild) {
    vector<int> inDegree(n);
    int root = -1;

    // If inDegree of any node > 1, return false
    for (const int child : leftChild)
      if (child != -1 && ++inDegree[child] == 2)
        return false;

    for (const int child : rightChild)
      if (child != -1 && ++inDegree[child] == 2)
        return false;

    // Find the root (node with inDegree == 0)
    for (int i = 0; i < n; ++i)
      if (inDegree[i] == 0)
        if (root == -1)
          root = i;
        else
          return false;  // Multiple roots

    // didn't find the root
    if (root == -1)
      return false;

    return countNodes(root, leftChild, rightChild) == n;
  }

 private:
  int countNodes(int root, const vector<int>& leftChild,
                 const vector<int>& rightChild) {
    if (root == -1)
      return 0;
    return 1 +  //
           countNodes(leftChild[root], leftChild, rightChild) +
           countNodes(rightChild[root], leftChild, rightChild);
  }
};


Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]


class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    dfs(s, 0, ans);
    return ans;
  }

 private:
  void dfs(string& s, int i, vector<string>& ans) {
    if (i == s.length()) {
      ans.push_back(s);
      return;
    }
    if (isdigit(s[i])) {
      dfs(s, i + 1, ans);
      return;
    }

    s[i] = tolower(s[i]);
    dfs(s, i + 1, ans);
    s[i] = toupper(s[i]);
    dfs(s, i + 1, ans);
  }
};


Given a string s, find the longest palindromic subsequence’s length in s. You may assume that the maximum length of s is 1000.
  
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};


1650  Lowest Common Ancestor of a Binary Tree III
Description
Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:
class Solution {
 public:
   Node* lowestCommonAncestor(Node* p, Node* q) {
      unordered_set<Node*> m;
      Node* cur = p;
      while(cur!= nullptr){
        m.insert(cur)
        cur = cur ->parent
      }
      cur = q;
     while ( cur! = nullptr) {
       if (m.count(cur))
         break;
       else
         cur = cur->parent;
     }
     return cur;
  }
  // Same as 160. Intersection of Two Linked Lists
  Node* lowestCommonAncestor(Node* p, Node* q) {
    Node* a = p;
    Node* b = q;

    while (a != b) {
      a = a == nullptr ? q : a->parent;
      b = b == nullptr ? p : b->parent;
    }

    return a;
  }
};



1213  Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, 
  return a sorted array of only the integers that appeared in all three arrays.

  
class Solution {
 public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                 vector<int>& arr3) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
      const int mini = min({arr1[i], arr2[j], arr3[k]});
      if (arr1[i] == mini && arr2[j] == mini && arr3[k] == mini) {
        ans.push_back(mini);
        ++i;
        ++j;
        ++k;
      } else if (arr1[i] == mini) {
        ++i;
      } else if (arr2[j] == mini) {
        ++j;
      } else {
        ++k;
      }
    }

    return ans;
  }
};



Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

  class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    unordered_map<int, int> m;
    for (int i = 0; i < post.size(); ++i)
      m[post[i]] = i;
    return build(pre, 0, pre.size() - 1, post, 0, post.size() - 1, m);
  }

 private:
  TreeNode* build(const vector<int>& pre, int preStart, int preEnd,
                  const vector<int>& post, int postStart, int postEnd,
                  const unordered_map<int, int>& m) {
    if (preStart > preEnd)
      return nullptr;
    if (preStart == preEnd)
      return new TreeNode(pre[preStart]);

    const int rootVal = pre[preStart];
    const int leftRootVal = pre[preStart + 1];
    const int leftRootPostIndex = postToIndex.at(leftRootVal);
    const int leftSize = leftRootPostIndex - postStart + 1;

    TreeNode* root = new TreeNode(rootVal);
    root->left = build(pre, preStart + 1, preStart + leftSize, post, postStart,
                       leftRootPostIndex, postToIndex);
    root->right = build(pre, preStart + leftSize + 1, preEnd, post,
                        leftRootPostIndex + 1, postEnd - 1, postToIndex);
    return root;
  }
};


class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre, 0, (int)pre.size() - 1, post, 0, (int)post.size() - 1);
    }
    TreeNode* helper(vector<int>& pre, int preL, int preR, vector<int>& post, int postL, int postR) {
        if (preL > preR || postL > postR) return nullptr;
        TreeNode *node = new TreeNode(pre[preL]);
        if (preL == preR) return node;
        int idx = -1;
        for (idx = postL; idx <= postR; ++idx) {
            if (pre[preL + 1] == post[idx]) break;
        }
        node->left = helper(pre, preL + 1, preL + 1 + (idx - postL), post, postL, idx);
        node->right = helper(pre, preL + 1 + (idx - postL) + 1, preR, post, idx + 1, postR - 1);
        return node;
    }
};

1008 Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node,
 any descendant ofnode.left has a value < node.val, and any descendant of node.
 right has a value > node.val.  Also recall that a preorder traversal displays the 
 value of the node first, then traverses node.left, then traverses node.right.)

It’s guaranteed that for the given test cases there is always possible to find 
a binary search tree with the given requirements.


class Solution {
 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    stack<TreeNode*> stack{{root}};

    for (int i = 1; i < preorder.size(); ++i) {
      TreeNode* parent = stack.top();
      TreeNode* child = new TreeNode(preorder[i]);
      // Adjust parent
      while (!stack.empty() && stack.top()->val < child->val)
        parent = stack.top(), stack.pop();
      // Create parent-child link according to BST property
      if (parent->val > child->val)
        parent->left = child;
      else
        parent->right = child;
      stack.push(child);
    }

    return root;
  }
};

The system should support the following functions:

Search: Finds the cheapest 5 shops that have an unrented copy of a given movie. The shops should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopi should appear first. If there are less than 5 matching shops, then all of them should be returned. If no shop has an unrented copy, then an empty list should be returned.
Rent: Rents an unrented copy of a given movie from a given shop.
Drop: Drops off a previously rented copy of a given movie at a given shop.
Report: Returns the cheapest 5 rented movies (possibly of the same movie ID) as a 2D list res where res[j] = [shopj, moviej] describes that the jth cheapest rented movie moviej was rented from the shop shopj. The movies in res should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopj should appear first, and if there is still tie, the one with the smaller moviej should appear first. If there are fewer than 5 rented movies, then all of them should be returned. If no movies are currently being rented, then an empty list should be returned.
Implement the MovieRentingSystem class:

MovieRentingSystem(int n, int[][] entries) Initializes the MovieRentingSystem object with n shops and the movies in entries.
List<Integer> search(int movie) Returns a list of shops that have an unrented copy of the given movie as described above.
void rent(int shop, int movie) Rents the given movie from the given shop.
void drop(int shop, int movie) Drops off a previously rented movie at the given shop.
List<List<Integer>> report() Returns a list of cheapest rented movies as described above.
Note: The test cases will be generated such that rent will only be called if the shop has an unrented copy of the movie, and drop will only be called if the shop had previously rented out the movie.



class MovieRentingSystem {

public:
    unoreded_map<int, unordered_map<int,int> prices; //shop movice : prices
    unordered_map<int, set<pair<int,int>> dropped; //[movie] {pirce shop}
    set<array<int,3>> rented; //price shop movie
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e:entries) { //shope movie prices
            dropped[e[1]].insert({e[2], e[0]});
            prices[e[0]][e[1]] = e[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        for (auto &[price, shop]:dropped[movie]){
            res.push_back(shop);
            if (res.size() == 5)
                break;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = prices[shop][movie];
        dropped[movie].erase(doppped[movie].find({price,shop}));
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = prices[shop][movie];
        rented.erase(rent.find({price, shop, movie}));
        dropped[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto &[price, shop, movie]:rented) {
            res.push_back({shop, movie});
            if (res.size() == 5)
                break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
* vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

 1060 Given a sorted array A of unique numbers, find the K-th missing number starting from the leftmost number of the array.
class Solution {
 public:
  int missingElement(vector<int>& nums, int k) {
    int l = 0;
    int r = nums.size();

    // # of missing numbers in [nums[0], nums[i]]
    auto nMissing = [&](int i) { return nums[i] - nums[0] - i; };

    // Find the first index l s.t. nMissing(l) >= k
    while (l < r) {
      const int m = (l + r) / 2;
      if (nMissing(m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return nums[l - 1] + (k - nMissing(l - 1));
  }
};

377 Given an integer array with all positive numbers and no duplicates, 
  find the number of possible combinations that add up to a positive integer target.

  class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;

         for (int i = 1; i <= target; ++i) {
            for (auto a : nums) {
                if (i >= a) dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
};
  

