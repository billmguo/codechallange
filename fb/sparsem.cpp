
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



Sparsity 

1.

In linked list, each node has four fields. These four fields are defined as:

Row: Index of row, where non-zero element is located
Column: Index of column, where non-zero element is located
Value: Value of the non zero element located at index – (row,column)
Next node: Address of the next node

struct Node
{
    int value;
    int r;
    int c;
    struct Node *next;
};

void create_new_node(Node *&head, Node *&tail, int val, int r, int c )
{
    Node *cur, *r;
    cur = start;
    Node *newnode = new Node(val, r, c);
    if (head == NULL) {
        head = newnode;
    } else {
        tail -> next = newnode;
        tail = tail -> next;
    }
}

2.
map< pair<int,int>, int > new_matrix;

3.
struct row_list
{
    int r;
    struct row_list *link_down;
    struct value_list *link_right;
};
 
// Node to represent triples
struct value_list
{
    int c;
    int value;
    struct value_list *next;
};

4.

Input : 0  0  0  0
        5  8  0  0
        0  0  3  0
        0  6  0  0

Solution: When the matrix is read row by 
          row, the A vector is [ 5 8 3 6]
          The JA vector stores column indices
          of elements in A hence, JA = [ 0 1 2 
           1]. IA[0] = 0. IA[1] = IA[0] + no  
          of non-zero elements in row 0 
          i.e 0 + 0 = 0.
          Similarly,
          IA[2] = IA[1] + 2 = 2
          IA[3] = IA[2] + 1 = 3  
          IA[4] = IA[3]+1 = 4
          Therefore IA = [0 0 2 3 4]
          The trick is remember that IA[i]
          stores NNZ upto and not-including 
          i row.

Input : 10  20  0  0  0  0
         0  30  0  4  0  0
         0   0 50 60 70  0
         0   0  0  0  0 80

Output :  A = [10 20 30 4 50 60 70 80],
         IA = [0 2 4 7 8]
         JA = [0  1 1 3 2 3 4 5]


SPARSIFY (MATRIX)
Step 1: Set M to number of rows in MATRIX
Step 2: Set N to number of columns in MATRIX
Step 3: I = 0, NNZ = 0. Declare A, JA, and IA. 
        Set IA[0] to 0
Step 4: for I = 0 ... N-1
Step 5: for J = 0 ... N-1
Step 5: If MATRIX [I][J] is not zero
           Add MATRIX[I][J] to A
           Add J to JA
           NNZ = NNZ + 1
        [End of IF]
Step 6: Add NNZ to IA
        [ End of J loop ]
        [ End of I loop ]
Step 7: Print vectors A, IA, JA
Step 8: END


 for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (M[i][j] != 0) {
                A.push_back(M[i][j]);
                JA.push_back(j);
                NNZ++;
            }
        }
        IA.push_back(NNZ);
    }

