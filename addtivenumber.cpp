/*dditive number is a positive integer whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.

1 + 99 = 100, 99 + 100 = 199

*/

bool isAdditiveNumber(string num) {
    for(int i=1; i<=num.size()/2; i++){
        for(int j=1; j<=(num.size()-i)/2; j++){
		    if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
            }
        }
        return false;
}
bool check(string num1, string num2, string num){
    if(num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;
    string sum=add(num1, num2);
    if(num==sum) return true;
    if(num.size()<=sum.size() || sum.compare(num.substr(0,sum.size()))!=0) return false;
    else 
    	return check(num2, sum, num.substr(sum.size()));
}
string add(string n, string m) {
    string res = to_string(atoll(n.c_str()) + atoll(m.c_str()));
    return res;
}

