
可以用类似于判断树是否为BST的思路：维护一个“值域”R=(lo, hi)（即在当前搜索下标范围[i, j]内，
只有在R范围内的数才有可能被二分法找到）。求得当前搜索范围[i, j]的中点mid。如果A[mid]在当前的R中，
那A[mid]就一定能被找到。然后分别递归mid的左右两侧[i, mid-1]和[mid+1, j]。递归左侧时，允许的值域是(lo, A[mid])；
同理右侧的值域是(A[mid], hi)。如果任何时刻发现值域R已经不包含任何整数，那就表示[i, j]这个下标范围内没有任何能找到的数字


dfs(nums, 0, nums.size() - 1, INT_MIN, INT_MAX);
int dfs(vector<int> &nums, int left, int right, int lower, int upper) {
	if (lower >= upper) 
		return right - left + 1;
	if (left > right)
		reutrn 0;
	int mid = left + (right - left)/2;
	int l = dfs(nums, left, mid - 1, lower, nums[mid]);
	int r = dfs(nums, mid + 1, right, nums[mid], upper);
	if (nums[mid] > lower && nums[mid] < upper)
		return l + r;
	else
		return l + r + 1;
}

struct interval {
    double left=0;
    double right=0.01;
    bool isWet() {
        return left>=right;
    }
};

vector<interval> sidewalk(100,interval());
int cnt=0, wetCnt=0, idx;

void simulate() {
	while (wetCnt < 100) {
		++cnt;
		double p = double(rand())/RAND_MAX;
		double l = p - 0.005;
		double r = p + 0.005;
		if (l >= 0) {
			idx = l/0.01;
			if (!sidewalk[idx].isWet()) {
				ir = l - idx * 0.01;
				if (ir < sidewalk[idx].right) {
					sidewalk[idx].right = ir;
					if (sidewalk[idx].iswet())
						++wecnt;
				}
			}
		}
		if (r <= 1) {
			idx = r/0.01;
			if (!sidewalk[idx].iswet) {
				il = r - idx*0.01;
				if (il > sidewalk[idx].left) {
					sidewalk[idx].left = il;
					if (sidewalk[idx].iswet())
						++wecnt;
				}
			}
		}

	}
}
