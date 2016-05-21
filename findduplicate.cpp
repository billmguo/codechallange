class soultion{
public:
	int findduplicate(vector<int> &nums){
		int l = 0; int r = nums.size() - 1;
		while(l<=r){
			int mid = l + (r - l)/2;
			int cnt = countnums(nums,mid);
			if (cnt <= m )
				l = m + 1;
			else
				r = m - 1;
		
		}
		return l;
	}
	int countnums(vector<int> &nums, int pos){
		int cnt = 0;
		for (int i=0;i<nums.size();i++){
			if (nums[i] <= pos)
				cnt++;
		}
		return cnt;
	}
}
