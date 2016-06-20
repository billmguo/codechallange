ort transformed array(elmirap) 

Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = a*x^2+b*x+c to each element x in the array.

The returned array should be sorted.

Expected time complexity : O(n)

Example


nums = [-4 , -2 , 2 , 4] , a = 1 , b = 3 , c = 5,

Result: [3, 9, 15, 33]

nums = [-4 , -2 , 2 , 4] , a = -1 , b = 3 , c = 5

Result: [-23, -5, 1, 7]


Solution 1:
#include <iostream>
#include <functional>
#include <vector>
using namespace std;
class Soultion{
public:
        vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
            vector<int> res(nums.size());
            if (nums.size() == 0) return res;
            int lindex = 0, i = 0;
            int rindex = nums.size() - 1, j = nums.size() - 1;
            
            while(i <= j) {
            	int sumi = transform(nums[i],a,b,c);
            	int sumj = transform(nums[j],a,b,c);
            	if (a > 0) {
            		if (sumi > sumj){ 
            			res[rindex--] = sumi;
            			i++;
            		}	
            		else{
            			res[rindex--] = sumj;
            			j--;
            		}
            	}else {
            		if (sumi < sumj) {
            			res[lindex++] = sumi;
            			i++;
            		}	
            		else{
            			res[lindex++] = sumj;
            			j--;
            		}	
            	}
            		
            }
            return res;
        }

        int transform(int num, int a, int b, int c) {
            return a * num * num + b * num + c;
        }
};        
int main() {
	Soultion sl;
	//vector<int> nums {-4 , -2 , 2 , 4};
	vector<int> nums {-4 , -2 , 2 , 4};
	vector<int> res = sl.sortTransformedArray(nums,-1,3,5);
	for (auto a:res)
		cout<<a<<endl;
	// your code goes here
	return 0;
}

Soution 2:


:
