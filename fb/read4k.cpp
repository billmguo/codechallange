Missing number

class solution{
public:
    int missingElement(vector<int>& nums, int k) {
        const int n = nums.size();
        int ms = nums[n - 1] - nums[0] - (n - 1);
        if (ms < k)
            return nums[n - 1] + k - ms;
        int l = 0, r = n - 1;
        while ( l < r) {
            int mid = l + ( r - l)/2;
            int t = nums[mid] - nums[l] - (mid - l);
            cout << "mid" << mid << "t" << t <<"v"<< nums[mid] <<"l" <<l <<" r" <<r<<endl;
            if (t < k) {
                l = mid ;
                k -= t;
            }else
                r = mid - 1;
        }
        cout << l << "k" << k << endl;
        return nums[l] + k;

    }
};

hindex = 1, 2
int hIndex(vector<int>& citations) {
    if(citations.empty())
        return 0;
    int n = citations.size();
    vector<int> hash(n + 1, 0);
    for(int i = 0; i < n; ++i){
        if(citations[i] >= n)
            hash[n]++;
        else
            hash[citations[i]]++;
    }
    int paper = 0;
    for(int i = n; i >= 0; --i){
        paper += hash[i];
        if(paper >= i)
            return i;
    }
}

case 1: citations[mid] == len-mid, then it means there are citations[mid] papers that 
have at least citations[mid] citations.
case 2: citations[mid] > len-mid, then it means there are citations[mid] papers that
 have moret than citations[mid] citations, so we should continue searching in the left half
case 3: citations[mid] < len-mid, we should continue searching in the right side


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left=0, len = citations.size(), right= len-1,  mid;
        while(left < right) {
            mid=(left + right)>>1;
            if(citations[mid]== (len-mid))
                return citations[mid];
            else if(citations[mid] > (len-mid))
                    right = mid;
            else 
                    left = mid + 1;
        }
        return len - (right + 1);
    }
};

class Reader{
public:
	int Read(char *buf, int n) {
		constexpr int buflen{4096};
		char buffer[buflen];
		int remain = n;
		int cnt = 0, n_rb = 4K;
		
		while (remain > 0 && n_rb == 4K) {
			int n_rb = Read4K(buffer);
			if (n_rb >= remain) {
				memcpy(buf + cnt, buffer, remain);
				return n;
			}else{
				memcpy(buf + cnt, buffer, n_rb);
				cnt += n_rb;
				remain -= n_rb;
			}
		}
		return cnt;
	}
};
