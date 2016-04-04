[i]<s[i+1]。如果不存在，
则表明该permutation已经最大，next permutation为当前序列的逆序。
2. 在s[i+1:n-1]中找一个j，使s[j]>s[i]>=s[j+1]，swap(s[i], s[j])
3. 将s[i+1:n-1]排序，从低位到高位单调递减。


class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<2) return;
        int n = num.size(), j = n-2;
        while(j>=0 && num[j]>=num[j+1]) j--;
        
        if(j<0) {
            sort(num.begin(),num.end());
            return;
        } 
        
        int i=j+1;
        while(i<n && num[i]>num[j]) i++;
        i--;
        
        swap(num[i],num[j]);
        sort(num.begin()+j+1, num.end());
    }
};

class Solution {
public:
    void prevPermutation(vector<int> &num) {
        if(num.size()<2) return;
        int n = num.size(), j = n-2;
        //find end of uptrend sequence 
        while(j>=0 && num[j]<=num[j+1]) j--;
        
        if(j<0) {
            sort(num.begin(),num.end());
            return;
        } 
        
        int i=j+1;
        while(i<n && num[i]<num[j]) i++;
        i--;
        
        swap(num[i],num[j]);
        sort(num.begin()+j+1, num.end(),greater<int>());
    }
};
