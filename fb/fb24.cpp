
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:

[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

class MedianFinder {
 public:
  void addNum(int num) {
    if (maxHeap.empty() || num <= maxHeap.top()) {
      maxHeap.push(num);
    }else
      minheap.push(num);

    if (maxheap.size() < minHeap.size()) {
        maxheap.push(minheap.top());
        minheap.pop();
    } else if (maxHeap.size() - minheap.size() > 1) {
        minHeap.push_back(maxheap.top());
        maxheap.pop();
    }

  }

  double findMedian() {
      if (maheap.size() == minheap.size())
        return maxHeap.top() + minHeap.top()/2.0;
      else
        return maxHeap.top();
  }

 private:
      priority_queue<int> maxHeap;
      priority_queue<int, vector<int>, greater<>> minHeap;
};

Matching Pairs
Given two strings s and t of length N, find the maximum number of possible matching pairs in strings s and t after swapping exactly two characters within s.
A swap is switching s[i] and s[j], where s[i] and s[j] denotes the character that is present at the ith and jth index of s, respectively. The matching pairs of the two strings are defined as the number of indices for which s[i] and t[i] are equal.
Note: This means you must swap two characters at different indices.
Signature
int matchingPairs(String s, String t)
Input
s and t are strings of length N
N is between 2 and 1,000,000
Output
Return an integer denoting the maximum number of matching pairs
Example 1
s = "abcd"
t = "adcb"
output = 4


int matchingPairs(string s, string t) {
  int count = 0;
  int = s.size():
  set<stringz> us;
  unordered_map<char,char> m;
  for (int i = 0; i < n; ++i) {
    if (s[i] == t[i])
      cnt++;
    else 
      us.add(s[i]+t[i]);
    
  }
  for (auto a:us) {
     strings s = a[1] + a[0];
     if (us.count(s))
         count += 2;
  }
  if (us.size() <= 1)
        count--
  if (us.size() == 0)
      count--;
  return count;

}

/*Nodes in a Subtree
You are given a tree that contains N nodes, each containing an
integer u which corresponds to a lowercase character c in the string
s using 1-based indexing. You are required to answer Q queries of
type [u, c], where u is an integer and c is a lowercase letter. The
query result is the number of nodes in the subtree of node u
containing c.

Signature:
int[] countOfNodes(Node root, ArrayList<Query> queries, String s)

Input
A pointer to the root node, an array list containing Q queries of
type [u, c], and a string s

Constraints
N and Q are the integers between 1 and 1,000,000 u is an integer
between 1 and N s is of the length of N, containing only lowercase
letters c is a lowercase letter contained in string s Node 1 is the
root of the tree

Output
An integer array containing the response to each query

*/
 void countOfNodesChar(Node* root, map<int, vector<int>> m, string s){
 
    int count[26];
    
    for (auto child : root.children) {
      countOfNodesChar(child, m, s);
      auto childCount = m[child.val];
      for (int i = 0; i < 26; i++) {
        count[i] += childCount[i];
      }
    }

    count[s[root->val] - 'a'] ++;
    m[root->val] = count;
  }

vector<int>  countOfNodes(Node root, vector<pair<char,int>> queries, string s) {

    map<int, vector<int>> map;
    vector<int> res;
    countOfNodesChar(root, map, s);
    for (auto q:queries) {
      res.push_back[q.first][q.second - 'a'];
    }
    return res;
}

Minimum Length Substrings
You are given two strings s and t. You can select any substring of string s and rearrange the characters of the selected substring. Determine the minimum length of the substring of s such that string t is a substring of the selected substring.
Signature
int minLengthSubstring(String s, String t)
Input
s and t are non-empty strings that contain less than 1,000,000 characters each
Output
Return the minimum length of the substring of s. If it is not possible, return -1
Example
s = "dcbefebce"
t = "fd"
output = 5

Explanation:
Substring "dcbef" can be rearranged to "cfdeb", "cefdb", and so on. String t is a substring of "cfdeb". Thus, the minimum length required is 5.


class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return minlen;
    }
};

Contiguous Subarrays
You are given an array arr of N integers. For each index i, you are required to determine the number of contiguous subarrays that fulfills the following conditions:
The value at index i must be the maximum element in the contiguous subarrays, and
These contiguous subarrays must either start from or end on index i.
Signature
int[] countSubarrays(int[] arr)
Input
Array arr is a non-empty list of unique integers that range between 1 to 1,000,000,000
Size N is between 1 and 1,000,000
Output
An array where each index i contains an integer denoting the maximum number of contiguous subarrays of arr[i]
Example:
arr = [3, 4, 1, 6, 2]
output = [1, 3, 1, 5, 1]
Explanation:
For index 0 - [3] is the only contiguous subarray that starts (or ends) with 3, and the maximum value in this subarray is 3.
For index 1 - [4], [3, 4], [4, 1]
For index 2 - [1]
For index 3 - [6], [6, 2], [1, 6], [4, 1, 6], [3, 4, 1, 6]
For index 4 - [2]


Maintain a stack such that it always contains the index for the last maximum encountered.
If the next element is greater than the arr[stack.peek()] then pop the top of the stack till
 we find a equal or greater element.
* If stack is empty then it means that the current element is the maximum of all
 and hence there are (current index + 1) possible arrays meeting the criteria.
* If stack is not empty, then (current index - stack top) will be possible arrays for the index position
Repeat the same steps from end of the array to get the final solution.

vector<int> findCountOfContiguousSubArrayOptimized(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> res;
        res[0] = 1;
        st.push(0);
        for (int i = 1; i < arr.size(); i++) {
          while(!st.empty() && arr[st.stop()] < arr[i]){
            st.pop();
            if (st.empty())
              res[i] = i + 1;
            else 
              res[i] = i - st.top();
          }
          st.push(i);
        }
        st.clear();
        st.push(n - 1);
        for (int i = n - 2; i >= 0; --i) {
          while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
            if (st.empty())
              res[i] += (n - i - 1);
            else
              res[i] += st.top() - i - 1;
          }
          st.push(i);
        }
        return res;
    }
Passing Yearbooks
There are n students, numbered from 1 to n, each with their own yearbook. They would like to
pass their yearbooks around and get them signed by other students.
You're given a list of n integers arr[1..n], which is guaranteed to be a permutation of
	1..n (in other words, it includes the integers from 1 to n exactly once each,
in some order). The meaning of this list is described below.
Initially, each student is holding their own yearbook. The students will then repeat the 
following two steps each minute: Each student i will first sign the yearbook that they're currently holding (which may either belong to themselves or to another student), and then they'll pass it to student arr[i-1]. It's possible that arr[i-1] = i for any given i, in which case student i will pass their yearbook back to themselves. Once a student has received their own yearbook back, they will hold on to it and no longer participate in the passing process.
It's guaranteed that, for any possible valid input, each student will eventually receive 
	their own yearbook back and will never end up holding more than one yearbook at a time.
You must compute a list of n integers output, whose element at i-1 is equal to the number of signatures that will be present in student i's yearbook once they receive it back.

	vector<int> sigcount(vector<int> &arr) {
		int n = arr.size();
		vector<int> res(n, 1);
		for (int i = 0; i < arr.size(); ++i) {
			int j = i;
			while(arr[j] != i + 1) {
				res[i]++;
				j = arr[j] - 1;
			}
		}
		return res;
	}
    
/*Queue Removals
You're given a list of n integers arr, which represent elements in a queue (in order from front to back). You're also given an integer x, and must perform x iterations of the following 3-step process:
Pop x elements from the front of queue (or, if it contains fewer than x elements, pop all of them)
Of the elements that were popped, find the one with the largest value (if there are multiple such elements, take the one which had been popped the earliest), and remove it
For each one of the remaining elements that were popped (in the order they had been popped), decrement its value by 1 if it's positive (otherwise, if its value is 0, then it's left unchanged), and then add it back to the queue
Compute a list of x integers output, the ith of which is the 1-based index in the original array of the element which had been removed in step 2 during the ith iteration.
Signature
int[] findPositions(int[] arr, int x)
Input
x is in the range [1, 316].
n is in the range [x, x*x].
Each value arr[i] is in the range [1, x].

*/

vector <int> findPositions(vector <int> arr, int x) {
  
  // put all elemens in a queue with their original indexes
  queue<pair<int,int>> q, qt;
  for (int i = 0; i< arr.size(); i++) {
    q.push(make_pair(arr[i], i + 1)); // Note that index must be 1-based index
  }
  
  vector<int> output;
  
  for (int i = 0; i < x; i++) {
    
    // 1) Extract X elements from the queue and place them in a temporary queue. 
    //Find the maximum while doing so

    pair<int, int> mx{-1,0};

    for (int j = 0; j < x && !q.empty(); j++) {
      auto val = q.front();
      if (val.first > mx.first) {
        mx = val;
      }
      qt.push(val);
      q.pop();
    }
    
    // 4) Put the index on the output array
    output.push_back(mx.second);
    
    // 3) For each of the elements (except for the max) reduce the value until it reachs 0
    while(!qt.empty()) {
      auto val = qt.front();
      qt.pop();
      if (val == mx) {// 2) We do not include the max item anymore in the queue
      	if (val.first > 0)
      		val.first--;
         q.push(val);
      }
    }
  }
  
  return output;
}

Element Swapping
Given a sequence of n integers arr, determine the lexicographically smallest sequence which may be obtained from it after performing at most k element swaps, each involving a pair of consecutive elements in the sequence.
Note: A list x is lexicographically smaller than a different equal-length list y if and only if, for the earliest index at which the two lists differ, x's element at that index is smaller than y's element at that index.

Signature
int[] findMinArray(int[] arr, int k)


vector<int> findMinArray(vector<int> &arr, int k) {
	for (int i = 0; i < arr.size() && k > 0: ++i) {
		int index = findMinAtDistanceK(arr, i, k);
		if (index == i)
			continue;
		reverse(arr.begin() + i, arr.begin() + index);
		k -= index - i;
	}
	return arr;
}

int findMinAtDistanceK(vector<int> arr, int start, int k) {
	int index = start, mn = INT_MAX;
	for (int i = start; i <= start +k ; ++i) {
		if (arr[i] < mn) {
			mn = arr[i];
			index = i;
		}
	}
}

/*
Encrypted Words
You've devised a simple encryption method for alphabetic strings that shuffles the characters in such a way that the resulting string is hard to quickly read, but is easy to convert back into the original string.
When you encrypt a string S, you start with an initially-empty resulting string R and append characters to it as follows:

Append the middle character of S (if S has even length, then we define the middle character as the left-most of the two central characters)
Append the encrypted version of the substring of S that's to the left of the middle character (if non-empty)
Append the encrypted version of the substring of S that's to the right of the middle character (if non-empty)
For example, to encrypt the string "abc", we first take "b", and then append the encrypted version of "a" (which is just "a") and the encrypted version of "c" (which is just "c") to get "bac".
If we encrypt "abcxcba" we'll get "xbacbca". That is, we take "x" and then append the encrypted version "abc" and then append the encrypted version of "cba".

Input
S contains only lower-case alphabetic characters
1 <= |S| <= 10,000

Output
Return string R, the encrypted version of S.
*/

string encrypt(string s) {
    if(s.size() <= 1)
        return s;
    int mid = (s.size() - 1) / 2;
    string left = encrypt(s.substr(0, mid));
    string right = encrypt(s.substr(mid + 1));
    return s[mid] + left + right;
}

string findEncryptedWord(string s) {
    return encrypt(s);
}

/*
Change in a Foreign Currency
You likely know that different currencies have coins and bills of different denominations. In some currencies, it's actually impossible to receive change for a given amount of money. For example, Canada has given up the 1-cent penny. If you're owed 94 cents in Canada, a shopkeeper will graciously supply you with 95 cents instead since there exists a 5-cent coin.
Given a list of the available denominations, determine if it's possible to receive exact change for an amount of money targetMoney. Both the denominations and target amount will be given in generic units of that currency.
Signature
boolean canGetExactChange(int targetMoney, int[] denominations)
Input
1 ≤ |denominations| ≤ 100
1 ≤ denominations[i] ≤ 10,000
1 ≤ targetMoney ≤ 1,000,000


Signature
boolean canGetExactChange(int targetMoney, int[] denominations)
Input
1 ≤ |denominations| ≤ 100
1 ≤ denominations[i] ≤ 10,000
1 ≤ targetMoney ≤ 1,000,000
*/


bool canGetExactChange(int target, vector<int> dims){
	if (target < 0)
		return falsel
	if (target == 0)
		return true;
	for (int i = 0; i < dims.size(): ++i) {
		if (canGetExactChange(target -dims[i], dims))
			return true;
	}
	return false;
}
/*Balanced Split
Given an array of integers (which may include repeated integers), determine if there's a way to split the array into two subsequences A and B such that the sum of the integers in both arrays is the same, and all of the integers in A are strictly smaller than all of the integers in B.
Note: Strictly smaller denotes that every integer in A must be less than, and not equal to, every integer in B.
Signature
bool balancedSplitExists(int[] arr)

*/

bool balancedSplitExists(vector<int> &arr) {
	int len = arr.size();
	if (len == 0)
		return false;
	sort(arr.begin(),arr.end());
	
	int rsum = arr[len - 1];
	int lsum = accumulate(arr.begin(), arr.end(), 0);
	lsum -= rsum;

	for (int i = len - 2; i >= 0; i--) {
		if (lsum == rsum )
			return true;
		if (lsum < rsum)
			break;
		lsum -= arr[i];
		rsum += arr[i];
	}
	return false;
}




Seating Arrangements

There are n guests attending a dinner party, numbered from 1 to n. The ith guest has a height of arr[i-1] inches.
The guests will sit down at a circular table which has n seats, numbered from 1 to n in clockwise order around the table. As the host, you will choose how to arrange the guests, one per seat. Note that there are n! possible permutations of seat assignments.
Once the guests have sat down, the awkwardness between a pair of guests sitting in adjacent seats is defined as the absolute difference between their two heights. Note that, because the table is circular, seats 1 and n are considered to be adjacent to one another, and that there are therefore n pairs of adjacent guests.
The overall awkwardness of the seating arrangement is then defined as the maximum awkwardness of any pair of adjacent guests. Determine the minimum possible overall awkwardness of any seating arrangement.
Signature
int minOverallAwkwardness(int[] arr)


-> Sort the Array in ascending order
-> Visualize that we need to arrange this data as a normal distribution (max comes in middle, mins goes in the edges) like

 A[0], A[2], A[4], ....A[n-2], A[n], A[n-1],......A[5], A[3], A[1]
 As this is a circle A[0] and A[1] are adjacent, and make note that A[n] and A[n-1] are adjacent
-> Calculate difference between every other item

 diff = A[i] - A[i -2]
-> special case diffs

 A[1]-A[0]
 A[n]-A[n-1]
-> return max of diffs



int minOverallAwkwardness(vector<int> &arr) {

    sort(begin(arr),end(arr))
    
    // Arrange the sorted arr in this way:
    // 0,2,4,...N-1,...,5,3,1
    
    // Adjacent ones are:
    // i and i - 2 
    // 0, 1
    // N - 1, N - 2
    
    int mx = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); ++i) {
    	mx = max(mx, abs(arr[i] - arr[i-2]));
    }
    // Note: We do not need to take into account diff of arr[N - 1] and arr[N - 2] as it can not be greater than diff of arr[N - 1] and arr[N - 3].
    // max = Math.max(max, Math.abs(arr[arr.length - 1] - arr[arr.length - 2]));
    return mx;
  }


Minimizing Permutations
In this problem, you are given an integer N, and a permutation, P of the integers from 1 to N, denoted as (a_1, a_2, ..., a_N). You want to rearrange the elements of the permutation into increasing order, repeatedly making the following operation:
Select a sub-portion of the permutation, (a_i, ..., a_j), and reverse its order.
Your goal is to compute the minimum number of such operations required to return the permutation to increasing order.

int minOperations(const vector <int> &arr) {
    string str;
    for (int x : arr) str.push_back(x + '0');

    unordered_set<string> visited; visited.insert(str);
    queue<string> q; q.push(std::move(str));

    for (int step = 0; !q.empty(); ++step) {
        for (size_t s = q.size(); s; --s) {
            auto str = std::move(q.front()); q.pop();
            if (std::is_sorted(str.begin(), str.end())) return step;

            for (int i = 0; i < str.size(); ++i) {
                for (int j = i + 2; j <= str.size(); ++j) {
                    reverse(str.begin() + i, str.begin() + j);
                    if (visited.insert(str).second) q.push(str);
                    reverse(str.begin() + i, str.begin() + j);
                }
            }
        }
    }
    return 0;
}



1539. Kth Missing Positive Number

 Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

 Find the kth positive integer that is missing from this array.


 Example 1:

 Input: arr = [2,3,4,7,11], k = 5
 Output: 9
 Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.



class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int l = 0;
    int r = arr.size();

    // Find the first index l s.t. nMissing(l) = A[l] - l - 1 >= k
    while (l < r) {
      const int m = (l + r) / 2;
      if (arr[m] - m - 1 >= k)
        r = m;
      else
        l = m + 1;
    }

    // The k-th missing positive
    // = A[l - 1] + k - nMissing(l - 1)
    // = A[l - 1] + k - (A[l - 1] - (l - 1) - 1)
    // = A[l - 1] + k - (A[l - 1] - l)
    // = l + k
    return l + k;
  }
};

Given an array of integers preorder, which represents the preorder traversal of a 
BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search
tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any
descendant of Node.left has a value strictly less than Node.val, and any 
 descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node 
first, then traverses Node.left, then traverses Node.right.
 
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return nullptr;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }

Given the root of a binary search tree, return a balanced binary search tree with the same node values.
 If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
class Solution {
 public:
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;
    inorder(root, nums);
    return build(nums, 0, nums.size() - 1);
  }

 private:
  void inorder(TreeNode* root, vector<int>& nums) {
    if (root == nullptr)
      return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }

  // Same as 108. Convert Sorted Array to Binary Search Tree
  TreeNode* build(const vector<int>& nums, int l, int r) {
    if (l > r)
      return nullptr;
    const int m = (l + r) / 2;
    return new TreeNode(nums[m], build(nums, l, m - 1), build(nums, m + 1, r));
  }
};


Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.


// Time: O(N!)
// Space: O(N)
class Solution {
 public:
  vector<int> constructDistancedSequence(int n) {
    vector<int> ans(2 * n - 1);
    dfs(n, 0, 0, ans);
    return ans;
  }

 private:
  bool dfs(int n, int i, int mask, vector<int>& ans) {
    if (i == ans.size())
      return true;
    if (ans[i] > 0)
      return dfs(n, i + 1, mask, ans);

    // Greedily fill in descendingly.
    for (int num = n; num >= 1; --num) {
      if ((mask >> num & 1) == 1)
        continue;
      if (num == 1) {
        ans[i] = num;
        if (dfs(n, i + 1, mask | 1 << num, ans))
          return true;
        ans[i] = 0;
      } else {  // num in [2, n]
        if (i + num >= ans.size() || ans[i + num] > 0)
          continue;
        ans[i] = num;
        ans[i + num] = num;
        if (dfs(n, i + 1, mask | 1 << num, ans))
          return true;
        ans[i + num] = 0;
        ans[i] = 0;
      }
    }

    return false;
  }
};


Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and 
"rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"}
and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  
 Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list A of strings.  Every string in A is an anagram of every other string in A. 
 How many groups are there?
class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int res = 0, n = A.size();
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!isSimilar(A[i], A[j])) continue;
                root[getRoot(root, j)] = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (root[i] == i) ++res;
        }
        return res;
    }
    int getRoot(vector<int>& root, int i) {
        return (root[i] == i) ? i : getRoot(root, root[i]);
    }
    bool isSimilar(string& str1, string& str2) {
           for (int i = 0, cnt = 0; i < str1.size(); ++i) {
               if (str1[i] == str2[i]) continue;
               if (++cnt > 2) return false;
           }
           return true;
       }
};


count hills and Valley
class Solution {
 public:
  int countHillValley(vector<int>& nums) {
    int ans = 0;
    int left = nums[0];

    for (int i = 1; i + 1 < nums.size(); ++i)
      if (left < nums[i] && nums[i] > nums[i + 1] ||  // Hill
          left > nums[i] && nums[i] < nums[i + 1]) {  // Valley
        ++ans;
        left = nums[i];
      }

    return ans;
  }
};


Given a m x n matrix grid which is sorted in non-increasing order both row-wise and

column-wise, return the number of negative numbers in grid.

 class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;
    int i = m - 1;
    int j = 0;

    while (i >= 0 && j < n) {
      if (grid[i][j] < 0) {
        ans += n - j;
        --i;
      } else {
        ++j;
      }
    }

    return ans;
  }
};


Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0

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
