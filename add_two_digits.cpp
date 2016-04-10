nclude <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> plusOne(vector<int>& num1, vector<int> &num2){
	int len1 = num1.size();
	int len2 = num2.size();
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());
	int maxlen = (len1 > len2)?len1:len2;
	vector<int> res(maxlen, 0);
	int sum,carry = 0;
	//cout<<maxlen<<endl;
	for (int i=0;i<maxlen;i++){
		int val1 = ((i > len1)? 0:num1[i]);
		int val2 = ((i > len2)? 0:num2[i]);
		sum = val1 + val2 + carry;
		res[i] = sum % 10;
		carry =  sum/10;
		sum = 0;
	}
	if (carry)
		res.insert(res.end(),carry);
	reverse(res.begin(),res.end());
	return res;
}

int main() {
	vector<int> digits1{9, 9, 9};
	vector<int> digits2{9};
	vector<int> res;
	res = plusOne(digits1, digits2);
	for (auto item:res)
		cout<<item;
	// your code goes here
	return 0;
}
