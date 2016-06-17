/*
 bob enemy

 Given 2D grid, each cell is either a wall 'Y', an enemy 'X' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at empty cell.

Example

For the given grid

0 X 0 0
X 0 Y X
0 X 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)


class Solution {
public:
    int maxKilledEnimies(vector<vector<char>>& grid) {
        
    }
};
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxKilledEnimies(vector<vector<char>>& grid) {
    	if (grid.empty())
    		return 0;
    	int row = grid.size();
    	int col = grid[0].size();
    	int cnt  = 0;
    	vector<vector<int>> sum(row,vector<int>(col,0));
    	/*count the row info*/
    	for (int i = 0; i < row; i++){
    		int j = 0;
    		cnt = 0;
    		while(j < col) {
    			if (grid[i][j] == 'X')
    					cnt++;
    			if (grid[i][j] == 'Y'|| j == (col - 1)) {
	    			int k = grid[i][j] == 'Y'? j - 1:j;
	    			while ( k >= 0 && grid[i][k] != 'Y'){
	    				sum[i][k] += cnt;
	    				k--;
	    			}	
	    			cnt = 0;
    			}
    			j++;
    		}
    	}
    	
    	
    	/*count the col info*/
    	for (int j = 0; j < col; j++){
    		int i = 0;
    		cnt = 0;
    		while(i < row) {
    			if (grid[i][j] == 'X')
    				cnt++;
    			if (grid[i][j] == 'Y'|| i == (row - 1)) {
    				cout<<"i"<<i<<"j"<<j<<"cnt"<<cnt<<endl;
    				int k = (grid[i][j] =='Y') ? i - 1: i;
    				while ( k >= 0 && grid[k][j] != 'Y'){
    					sum[k][j] += cnt;
    					k--;
    				}	
    				cnt = 0;
    			}
    			i++;
    		}
    	}

     	int res = 0;
    	for (int i = 0; i < row; i++)
    		for (int j = 0; j < col; j++) {
    			sum[i][j] -= (grid[i][j] == 'X')? 1: 0;
    			res = max(sum[i][j], res);
    		}
      
        return res;
    }
};
int main() {
	// your code goes here
	Solution sl;
	vector<vector<char>> grid{
		{'0', 'X', '0', '0'},
		{'X', '0', 'Y', '0'},
		{'0', 'X', '0', '0'}
	};
	int res = sl.maxKilledEnimies(grid);
	cout<<res<<endl;
	return 0;
}
