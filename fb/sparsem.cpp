
norder Successor in Binary Search Tree
In Binary Tree, Inorder successor of a node is the next node in Inorder traversal
 of the Binary Tree. Inorder Successor is NULL for the last node in Inoorder traversal.
In Binary Search Tree, Inorder Successor of an input node can also be defined as the 
node with the smallest key greater than the key of input node. So, it is sometimes 
important to find next node in sorted order.


TreeNode *next(TreeNode *node) {
    TreeNode *cur = node;
    while (cur->left)
        cur = cur->left;
    return cur;
}
way 1: inordersuccessor(TreeNode *node) {
    if (root->right != NULL) {
        TreeNode * cur = root->right;
        while (cur->left)
            cur = cur->left;
        return cur;
    }
    TreeNode *p = node -> parent;
    while (p && n == p -> right) {
        n = p;
        p = p -> parent;
    }
    return p;
}

way 2:

TreeNode *inordersuccessor2(TreeNode *root, TreeNode *p) {
    if (p ->right) {
        cur = p -> right;
        while (cur->left)
            cur = cur->left;
        return cur;
    }
    TreeNode *next;
    while (root != NULL) {
        if (root->val > p->val) {
            next = root;
            root = root->left;
        }else if (root->val < p->val) {
            root = root->right;
        } 
        else break;
    }
    return next;

}

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
       int m = A.size(), n = A[0].size(), l = B[0].size();
       vector<vector<int>> res(m, vector<int>(l, 0));
        vector<vector<pair<int, int>>> v(A.size(), vector<pair<int,int>>());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] != 0)
                    v[i].push_back({j, A[i][j]});
            }
        }
        for (int i= 0; i < m; i++) {
            for (int k = 0; k < v[i].size(); k++) {
                int col = v[i][k].first;
                int val = v[i][k].second;
                for (int j = 0; j < l; j++) {
                    res[i][j] += val*B[col][j];
                }
            }
        }
        return res;
    }
};




way3 


#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

typedef pair<int,int> Point;

struct myhash {
  size_t operator()(const Point& p) const {
    return p.first << 4| p.second;
  }
};

struct myeq {
  bool operator ()(const Point& p1, const Point& p2) const {
    return p1.first == p2.first && p1.second == p2.second;
  }
};

class SparseMatrixOperator {
public:
   vector<vector<int>> SparseMatrixMultiply(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
  vector<vector<int>> matrix_multiply;
    int m = matrix1.size(), n = matrix2.size(), r = matrix1[0].size();
    unordered_map<Point, int, myhash, myeq> m1;
    
    for (int i = 0 ; i < m; i++)
    for (int j = 0; j < r; j++) {
        if (matrix1[i][j]) {
            m1[{i,j}] = matrix1[i][j];  
        }
        
    }
    unordered_map<Point, int, myhash, myeq> m2;
     for (int i = 0 ; i < m; i++)
    for (int j = 0; j < r; j++) {
        if (matrix2[i][j]) {
            m2[{i,j}] = matrix2[i][j];  
        }
        
    }
    for (auto a:m1)
    cout <<a.first.first << a.first.second << "  " << a.second <<endl;
   
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < r; j++) {
        int element_multiply = 0;
        for (int k = 0; k < n; k++) {
          Point p1(i, k);
          Point p2(k, j);
          if (m1.count(p1) && m2.count(p2)) {
            element_multiply += m1[p1] * m2[p2];
          }
        }
        if (element_multiply != 0) {
          matrix_multiply.push_back({i, j, element_multiply});
        }
      }
    }
    return matrix_multiply;
  }

  void print(vector<vector<int>>& matrix, int m, int n) {
    unordered_map<Point, int, myhash, myeq> element_store;
    for (vector<int> iter : matrix) {
      Point p(iter[0], iter[1]);
      element_store[p] = iter[2];
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        Point p(i, j);
        if (element_store.find(p) != element_store.end()) {
          cout << element_store[p] << " ";
        } else {
          cout << "0" << " ";
        }
      }
      cout << endl;
    }
  }
};
int main() {
    // your code goes here
    vector<vector<int>> A{{ 1, 0, 0},  {-1, 0, 3}};
    vector<vector<int>> B{{ 7, 0, 0 },  { 0, 0, 0 }, { 0, 0, 1}};
    SparseMatrixOperator sl;
    vector<vector<int>> res = sl.SparseMatrixMultiply(A, B);
    sl.print(res, A.size(), B.size());
    return 0;
}
