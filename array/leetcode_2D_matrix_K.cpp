Given a 2D matrix A and an integer K, find the max sum of A's sub-matrix. The max sum should be no larger than K.

Example:

Given A = [
  [-1, 0, 1],
  [0, -2, 3]
]
K = 2
The answer is 2. Because the sum of sub-matrix [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than K(K = 2).

Note:
1. We make sure that the minimum sum of the sub-matrix is no larger than K.

2. What if the number of rows is much larger than the number of columns?
/* */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class NumMatrix {
public:
	int maxSumofSubmatrix(vector<vector<int>>& matrix, int K) {
     	if (matrix.size() < K || matrix[0].size() < K)
     		return 0;
     	int row = matrix.size();
     	int col = matrix[0].size();
     	configNumMatrix(matrix);
     	int res = INT_MIN;
     	for (int cnt = 1; cnt <= K; cnt++) {
	     	for (int i = 0; i < row - cnt ; i++) {
	     		for (int j = 0; j < col - cnt ;j++){
						int curs = sumRegion(i,j ,i + cnt ,j + cnt);
						res = max(res, curs);
	    			}
	     	}
		}
     	return res;
    }

    void configNumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
        	return;
        int row = matrix.size();
        int col = matrix[0].size();
        bit.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                update(i, j, matrix[i][j],row, col);
            }
        }
    }

    void update(int row, int col, int val, int rowsize, int colsize) {
        for (int i = row + 1; i <= rowsize; i += i&-i) {
            for (int j = col + 1; j <= colsize; j += j&-j) {
                bit[i][j] += val;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2 + 1, col2 + 1) - getSum(row1, col2 + 1) - getSum(row2 + 1, col1) + getSum(row1, col1);
    }
    
    int getSum(int row, int col) {
        int res = 0;
        for (int i = row; i > 0; i -= i&-i) {
            for (int j = col; j > 0; j -= j&-j) {
                res += bit[i][j];
            }
        }
        return res;
    } 
    
private:
    vector<vector<int>> bit;
};
int main() {
	NumMatrix nm;
	vector<vector<int>> matrix{ {-1, 0, 1},  {0, -2, 3}};
	int res = nm.maxSumofSubmatrix(matrix,2);
	cout<<res<<endl;
	return 0;
}`
