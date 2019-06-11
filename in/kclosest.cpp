#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
	    int len = points.size(), l = 0, r = len - 1;
	    while ( l < r) {
	        int mid = helper(points, l, r);
	        if (mid == K)
	            break;
	        if (mid < K)
	            l = mid + 1;
	        else
	            r = mid;
	    }
	    return vector<vector<int>>(points.begin(), points.begin() + K);
	}

	int compare(vector<int>& p1, vector<int>& p2) {
	    return p1[0] * p1[0] + p1[1] * p1[1] - p2[0] * p2[0] - p2[1] * p2[1];
	}
	
	int helper(vector<vector<int>> &A, int left, int right) {
	    vector<int> pivot = A[left];
	    int l = left + 1, r = right;
	    while (l <= r) {
	        if (compare(A[l], pivot) > 0 && compare(A[r], pivot) < 0)
	            swap(A[l++], A[r--]);
	        if (compare(A[r], pivot) >= 0)  
	            r--;
	        if (compare(A[l], pivot) <= 0)  
	            l++;
	    }
	    swap(A[left],A[r]);
	    return r;
	}

};
int main() {
	// your code goes here
	Solution sl;
	vector<vector<int>> points{{3,3},{5,-1},{-2,4}};
	vector<vector<int>> res = sl.kClosest(points, 2);
	for (auto a:res)
		cout<<a[0]<< " "<< a[1] << " ";
	cout<<endl;
	return 0;
}
