vector<int> twosums(vector<int> &nums, int target) {
	int l = 0, r = nums.size() - 1;
	vector<int> res;
	while( l < r ) {
		int sum = nums[l] + nums[r];
		if (sum == target) {
			res.push_back(l + 1);
			res.push_back(r + 1);
		} else if (sum < target) {
			l++;
		} else 
			r--;

	}
	return res;
}

Design and implement a TwoSum class. It should support the following operations:add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false


class Twosum {
public:
	void add(int num) {
		++m[num];
	}	
	bool find(int value) {
		for (auto &e:m) {
			int t = value - e.first;
			if ( t != e.first && m.count(t) || ( t == e.first && e.second > 1))
				return true;
		}
		return false;
	}
private:
	unordered_map<int, int> m;	
}
