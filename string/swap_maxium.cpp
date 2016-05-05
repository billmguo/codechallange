/*swap two numbers in a digit to get the maxium number*/
#include <iostream>
using namespace std;
int findmaxswap(string nums) {
 
    if (nums.size() == 0)
        return -1;
 
    int i;
    for (i = 0; i < nums.size() - 1; i++) {
        if (nums[i] < nums[i+1])
            break;
    }
   
    if ( i == (nums.size() - 1))
        return -1;
 
    int maxn = 0;
    int maxp;
    for (int j = i; j < nums.size();j++){
        if (nums[j] >= maxn){
            maxp = j;
        }
    }
 
    for (i = 0; i < nums.size();i++) {
        if (nums[i] < nums[maxp])
            break;
    }
    swap(nums[i],nums[maxp]);
    return stoi(nums);
}
int main() {
               // your code goes here
               string nums{"102"};
               int res = findmaxswap(nums);
               cout<<res<<endl;
               return 0;
}
 
