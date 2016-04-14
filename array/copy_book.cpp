ass Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int total = 0;
        int maxv;
        for (auto a:pages){
            total += a;
        	if (a > maxv)
        		maxv = a;
        }
        if (pages.size() <=k )
        	return maxv;
        	
        int l = 0, r = total;
        while( l < r ){
            int mid = l + (r - l) / 2;
            if (isvalid(pages, mid, k))
                r = mid ;
            else
                l = mid + 1;
        }
        return l;
    }
    
    bool isvalid(vector<int> &pages, int total, int k){
        int cnt = 0, res = 0;
        for (int i=0;i<pages.size();i++){
            res += pages[i];
            if (res > total){
                res -= pages[i];
                cnt++;
                res = pages[i];
            }
        }
        if (res != 0)
        	cnt++;
        return (cnt <= k);
    }
};
