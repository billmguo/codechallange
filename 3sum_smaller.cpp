int threeSumSmaller(vector<int>& nums, int target){
	if (nums.size() < 3)
		return 0;
	int res = 0;
	sort (nums.begin(),nums.end());
	for (int i=0;i<nums.size()-2;i++){
		int left = i + 1;
		int right = nums.size() - 1;
	    while (left < right){
			if (nums[i] + nums[left] + nums[right] < target){
				res += right - left;
				left++;
			}else
				right--
		}
	}
	return res;
}


int Trianglecount(vector<int> &nums){
	if (nums.size() < 3)
		return 0;
	int res = 0;
	sort (nums.begin(),nums.end());
	for (int i = num.size() - 1;i>1;i--){
		int left = 0;
		int right = i-1;
        while (left < right){
			if (nums[left] + nums[right] > nums[i]){
				res +=  right -left;
				right--;
			}else
				left++;
			
		}
	}
	return res;
	
}
