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

int read(char *buf, int sz) {
	int ck = sz/4K; n = sz%n;
	for (int i = 0; i < ck; i++) {
		int t = read4k(buf);
		if (t < 0)
			return i * 4K;
	}
	int start = ck * 4K;
	if (n == 0)
		return sz;
	for (int i = 0; i < n; i++) {
		if (readp == writep) {
			writep = read4K(lbuf);
			readp = 0;
			if (writep)
				return i + start;
		}else
			buf[start + i] = lbuf[readp++];
	}
	return sz;
}
