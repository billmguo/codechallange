/*
	Given an array a[0 . . . n-1]. We should be able to efficiently find the GCD from index qs (query start) to qe (query end) where 0 <= qs <= qe <= n-1.

Example :

Input : a[] = {2, 3, 60, 90, 50};
        Index Ranges : {1, 3}, {2, 4}, {0, 2}
Output: GCDs of given ranges are 3, 10, 1

*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;

class soultion {
public:
	vector<int> constructSegmentTree(vector<int> &arr)
	{
		int height = (int)ceil(log2(arr.size()));
		int size = (int)2 * pow(2, height) - 1;
		vector<int> st(size,0);
		constructST(arr, 0, arr.size() - 1, 0, st);
		return st;
	}

	// A recursive function that constructs Segment
	// Tree for array[ss..se]. si is index of current
	// node in segment tree st
	int constructST(vector<int> & arr, int ss,int se, int si,vector<int> &st)
	{
		if (ss==se)
		{
			st[si] = arr[ss];
			return st[si];
		}
		int mid = ss + (se-ss)/2;
		st[si] = GCD(constructST(arr,ss,mid,si*2 + 1,st),constructST(arr, mid+1, se,si*2 + 2,st));
		return st[si];
	}

	// Function to find GCD of 2 numbers.
	int GCD(int a, int b)
	{
		if (a < b)
		{
			swap(a,b);
		}

		if (b==0)
			return a;
		return GCD(b,a%b);
	}

	//Finding The GCD of given Range
	int findRangeGcd(int ss, int se, vector<int>& arr,vector<int> &st)
	{
		int n = arr.size();

		if (ss<0 || se > n-1 || ss>se)
			return -1;

		return findGcd(0, n-1, ss, se, 0,st);
	}

	int findGcd(int ss, int se, int qs, int qe, int si,vector<int> &st)
	{
		if (ss>qe || se < qs)
			return 0;

		if (qs <= ss && qe >= se)
			return st[si];

		int mid = ss+(se-ss)/2;
		return GCD(findGcd(ss, mid, qs, qe, si*2+1,st),findGcd(mid+1, se, qs, qe, si*2+2, st));
	}

};


int main() {
	// your code goes here
	vector<int> nums{2, 3, 6, 9, 5};
	soultion sl;
	vector<int> res = sl.constructSegmentTree(nums);
	int l = 1;
	int r = 3;
	int ans = sl.findRangeGcd(l,r,nums,res);
	cout<<ans<<endl;
	return 0;
}
