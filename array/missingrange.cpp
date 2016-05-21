Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, “51->74”, “76->99”]

vector<string> findmissingrange(vector<int> &nums,int begin, int end){
	nums.insert(nums.begin(),begin - 1);
	nums.push_back(end + 1);
	int l = 0;
	int r = nums.size() - 1;
	while ( l < r ) {
		while ( l < r  && nums[l] + 1 == nums[l+1] )
			l++;
		if ( l < r ){
			if (nums[l] + 2 == nums[l+1]) 
				res.push_back(to_string(nums[l] + 1);
			else
				res.push_back(to_string(nums[l] + 1) + "->" + to_string(nums[l+1] - 1);
		}
		l++;
	}
	return res;
}
