ven a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Hint:

A direct way is to use the backtracking approach.
Backtracking should contains three states which are (the current number, number of steps to get that number and a bitmask which represent which number is marked as visited so far in the current number). Start with state (0,0,0) and count all valid number till we reach number of steps equals to 10n.
This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.

1. DP

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        	if (n == 0)
			    return 1;
		    if (n == 1)
				return 10;
			
			n = min(10,n);
			int  sum = 10;
			int  cand = 9;
			for (int i = 1; i < n; i++) {
				cand *= 10 - i;
				sum += cand;
			}
			return sum;
    }
};

2.DFS, use visited to mark whether number is visited or not, for the start index with 0,  0 can not be used 

class Solution {
public:
    
    int countNumbersWithUniqueDigits(int n) {
     	   vector<bool> visited(10, false);
     	   int cnt = 0;
     	   for (int i = 0; i <= n; i++)
     		  cnt += dfscnt(0,i,visited);
     	   return cnt;
    }
    int dfscnt(int index, int n, vector<bool> visited) {
    	if (index == n) {
    		return 1;
    	}
    	int count = 0;
    	int i = index ? 0:1;
    	for (; i < 10; i++) {
    		if (visited[i] == 0){
    			visited[i] = 1;
    			count += dfscnt(index + 1, n, visited);
    			visited[i] = 0;
    		}
    	}
    	return count;
    }
};
