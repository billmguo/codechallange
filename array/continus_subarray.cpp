nclude <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
         
        int len = A.size();
        vector<int> res(2,0);
        int start = 0, end = 0;
        int sum = 0;
        int maxv = INT_MIN;
        int total = 0;
        for (int i = 0; i < len; ++i) {
        	total += A[i];
        	if (sum < 0) {
        		sum = A[i];
        		start = end = i;
        	}else {
              	sum += A[i];
              	end = i;
            }
            if (sum > maxv) {
            	maxv = sum;
                res[0] = start;
                res[1] = end;
            }
        }
        sum = 0;
        start = 0;
        end = -1;
        
        for (int i = 0; i < len;i++){
        	if (sum > 0){
        		sum = A[i];
        		start = end = i;	
        	}else{
        		sum += A[i];
        		end = i;
        	}
        	if (start == 0 || end == (len - 1)) 
        		continue;
        		
        	if (total - sum > maxv){
        		maxv = total - sum;
        		res[0] = (end + 1) % len;
        		res[1] = (start - 1 + len) % len;
        	}
        	
        }
        
        return res;
    }
};

int main() {
	// your code goes here
	vector<int> nums{1,-1, -2,4,-5, 2, 4, 5};
	Solution sl;
	vector<int> res = sl.continuousSubarraySum(nums);
	cout<<res[0]<<res[1]<<endl;
	return 0;
}
