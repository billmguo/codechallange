#include <iostream>
#include <vector>
 
using namespace std;
int res = 0;
class solution{
public:
               int numberofpatterns(int m, int n) {
                              vector<vector<bool>> keyboard(3,vector<bool>(3,false));
                              for (int k =m ; k <= n; k++) {
                                             for (int i = 0; i < 3; i++) {
                                                            for (int j = 0; j < 3; j++) {
                                                                           keyboard[i][j] = true;
                                                                           dfs(keyboard, k-1, i, j);
                                                                           keyboard[i][j] = false;
                                                            }
                                             }
                              }
               }
              
               void dfs(vector<vector<bool>> &kb, int left, int x, int y) {
                              if (left == 0) {
                                             res++;
                                             return;
                              }
                              for (int i = 0; i < 3; i++) {
                                             for (int j = 0; j < 3;j++ ){
                                                            if (kb[i][j]  \
                                                                           || (x == i && abs(y-j) > 1 && !kb[x][1]) \
                                                                           || (y == j && abs(x-i) > 1 && !kb[1][y])  \
                                                                           || (x == i && y == j)  \
                                                                           || (x + y == i + j && abs (x-i) > 1 && !kb[1][1]) \
                                                                           || (x - y == i - j && abs (x-i) > 1 && !kb[1][1]) )
                                                                           continue;
                                                            else{
                                                                           kb[i][j] = true;
                                                                           dfs(kb,left-1, i, j);
                                                                           kb[i][j] = false;
                                                            }
              
                                             }
                              }
               }
};
int main() {
               // your code goes here
               solution sl;
               sl.numberofpatterns(4,9);
               cout<<res<<endl;
               return 0;
}
 
/*
used is the 9-bit bitmask telling which keys have already been used and (i1,j1) and (i2,j2)are the previous two key coordinates. A step is valid if...

I % 2: It goes to a neighbor row or
J % 2: It goes to a neighbor column or
used2 & (1 << (I/2*3 + J/2))): The key in the middle of the step has already been used.
 
*/
 
#include <iostream>
#include <vector>
 
using namespace std;
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        return count(m, n, 0, 1, 1, 1, 1);
    }
private:
    int count(int m, int n, int used, int i1, int j1, int i2, int j2) {
        int number = m <= 0;
        if (!n) return 1;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                int I = i2 + i, J = j2 + j, used2 = used | (1 << (i*3 + j));
                if (used2 > used && (I % 2 || J % 2 || used2 & (1 << (I/2*3 + J/2))))
                    number += count(m-1, n-1, used2, i2, j2, i, j);
            }
        }
       return number;
    }
};
int main() {
               // your code goes here
               Solution sl;
               int res = sl.numberOfPatterns(4,9);
               cout<<res<<endl;
               return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numberOfPatterns(int m, int n) {
		vector<bool> visited(9, false);
		int res = 0;
		for (int i = 0; i < 9; i ++) {
          res += dfs(i, 1, m, n,visited);
        }
        return res;
    }
    int dfs(int start, int count, int m, int n, vector<bool> &visited) {
        int cnt = 0;
        if (count >= m)
        	cnt = 1;
        if (count  > n)
        	return 0;
        visited[start] = true;
        for (int i = 0; i < 9; i ++) {
            if (check(start, i, visited)) {
                	cnt +=  dfs(i, count + 1, m, n, visited);
            }
        }
        visited[start] = false;
       return cnt;
    }

    bool check(int a, int b,vector<bool> &visit){
	    if(visit[b]) return false;
	
	    int rowDis = abs(a / 3 - b / 3);
	    int colDis = abs(a % 3 - b % 3);
	
	    if(rowDis == 2 && colDis == 2) return visit[4];
	    if(rowDis == 2 && colDis == 0) return visit[1 * 3 + a % 3];
	    if(rowDis == 0 && colDis == 2) return visit[a / 3 * 3 + 1];
	    return true;
	}
};
int main() {
	Solution sl;
	int res = sl.numberOfPatterns(4,9);
	cout<<res<<endl;
	// your code goes here
	return 0;
} 
/*solution 3*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int cnt = 0;
	int numberOfPatterns(int m, int n) {
		vector<bool> visited(9, false);
		for (int i = 0; i < 9; i ++) {
          dfs(i, 1,cnt, m, n,visited);
        }
        return cnt;
    }
    void dfs(int start, int count, int &cnt, int m, int n, vector<bool> &visited) {
        if (count >= m && count <= n){
            ++cnt;
            if (count >= n)
        	return;
        }
        visited[start] = true;
        for (int i = 0; i < 9; i ++) {
            if (check(start, i, visited)) {
                visited[i] = true;
                dfs(i, count + 1, cnt, m, n, visited);
                visited[i] = false;
            }
        }
        visited[start] = false;
    }

    bool check(int a, int b,vector<bool> &visit){
	    if(visit[b]) return false;
	
	    int rowDis = abs(a / 3 - b / 3);
	    int colDis = abs(a % 3 - b % 3);
	
	    if(rowDis == 2 && colDis == 2) return visit[4];
	    if(rowDis == 2 && colDis == 0) return visit[1 * 3 + a % 3];
	    if(rowDis == 0 && colDis == 2) return visit[a / 3 * 3 + 1];
	    return true;
	}
};
int main() {
	Solution sl;
	int res = sl.numberOfPatterns(4,9);
	cout<<res<<endl;
	// your code goes here
	return 0;
}

 
 
Thanks/Min
 
