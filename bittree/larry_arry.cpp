https://www.hackerrank.com/challenges/larrys-array
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lowbit(int x){
    return x&-x;
}

void update(vector<int> &a, int idx, int n){
    for(int i = idx; i <= n; i += lowbit(i))
        a[i] += 1;
}

int sum(vector<int> &a, int idx){
    int res = 0;
    for(int i = idx; i > 0; i -= lowbit(i))
        res += a[i];
    return res;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int count,len;
    cin >> len;
    for (int i = 0; i < len; i++) {
    	vector<int> btree;
    	vector<int> arr;
    	int v, res = 0;
    	cin >> count;
	    for (int i = 0; i < count; i++) {
	        btree.resize(count+1);
	        cin >> v;
	        if (v != i + 1)
	            arr.push_back(v);
	    }    
	    for (int i = arr.size() - 1; i >= 0; i--) {
	            res += sum(btree,arr[i]);
	            update(btree, arr[i], count + 1);
	    }
	    if (res % 2 == 0)
	            cout<< "YES"<<endl;
	    else
	            cout<<"NO"<<endl;
	}
    return 0;
}

