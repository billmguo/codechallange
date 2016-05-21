/*Given an array of length n having integers 0 to n-1 in unsorted order.
Please modify this array such that the value at a[i] becomes a[a[i]].
For example, if a[0] = 5, a[0] will have value a[5] and so on.
e.g. {2, 4, 3, 1, 0} => {3, 0, 1, 4, 2}
This should take O(n) time complexity.
*/
void changeinplace(vector<int> &nums) {
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < nums.size()) {
			int start =  i;
			int next = nums[start];
			while (i != next) {
				int nexti = nums[next];
				swap(nums[start],nums[next]);
				nums[start] += num.size();
				start = next;
				next = nexti;
			}
			nums[start] += nums.size();
		}
	}
	for (auto a:nums) {
		a -= nums.size();
	}

}

