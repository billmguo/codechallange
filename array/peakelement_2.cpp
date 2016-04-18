s an integer matrix which has the following features:

The numbers in adjacent positions are different.
The matrix has n rows and m columns.
For all i < m, A[0][i] < A[1][i] && A[n - 2][i] > A[n - 1][i].
For all j < n, A[j][0] < A[j][1] && A[j][m - 2] > A[j][m - 1].
We define a position P is a peek if A[j][i] > A[j+1][i] && A[j][i] > A[j-1][i] && A[j][i] > A[j][i+1] && A[j][i] > A[j][i-1].

Find a peak element in this matrix. Return the index of the peak.

Example
Given a matrix:

[
  [1 ,2 ,3 ,6 ,5],
  [16,41,23,22,6],
  [15,17,24,21,7],
  [14,18,19,20,10],
  [13,14,11,10,9]
]
return index of 41 (which is [1,1]) or index of 24 (which is [2,2])

Note
The matrix may contains multiple peeks, find any of them.

Challenge
Solve it in O(n+m) time.

If you come up with an algorithm that you thought it is O(n log m) or O(m log n), can you prove it is actually O(n+m) or propose a similar but O(n+m) algorithm?
*/
class soultion{
public:
	vector<int> findpeakelement(vector<vector<int>> &nums){
		int l = 0;
		int r = nums.size() - 1;
		vector<int> res;
		while ( l <= r ) {
			int mid = l + (r - l) / 2;
			int col = findmax(nums[mid]);
			if ( nums[mid][col]  < nums[mid-1][col])
				r = mid - 1;
			else if (nums[mid][col] < nums[ mid+1][col])
				l = mid + 1;
			else{
				res.push_back(mid);
				res.push_back(col);
			}
		}
		return res;
		
	}

	bool findmax(vector<int>& row) {
		int col = 0;
		for (int i = 0; i < row.size() ;i++ ) {
			if (row[i] > col )
				col = i;
		}
		return col;
	}
};
vector<int> dfs(vector<int> &nums, int target, int start, int end){
	vector<int> res;
	if (start > end )
		return res;
	for (int i = start, i< end ;i++){
		vector<int> left = dfs(nums,target,start, i);
		vector<int> right = dfs(nums,target,i+1,end);
		for (auto l:left)
			for (auto r:right){
				res.add(l+r);
				res.add(l*r);
				if (r!=0)
					res.add(l/r);
				res.add(l-r);
			}

	}
	return res;
}
