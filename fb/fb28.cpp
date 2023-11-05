893. Groups of Special-Equivalent Strings


You are given an array A of strings.

Two strings S and T are  special-equivalent  if after any number of  moves , S == T.

A  move  consists of choosing two indices i and jwith i % 2 == j % 2, and swapping S[i] with S[j].

Now, a  group of special-equivalent strings fromA  is a non-empty subset S of A such that any string not in S is not special-equivalent with any string in S.

Return the number of groups of special-equivalent strings from A

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> st;
        for (string word : A) {
            string even, odd;
            for (int i = 0; i < word.size(); ++i) {
                if (i % 2 == 0) even += word[i];
                else odd += word[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            st.insert(even + odd);
        }
        return st.size();
    }
};

836. Rectangle Overlap
A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.



class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    return rec1[0] < rec2[2] && rec2[0] < rec1[2] &&  //
           rec1[1] < rec2[3] && rec2[1] < rec1[3];
  }
};

           ____________________x4,y4
          |                   |
   _______|______x2,y2        |
  |       |______|____________|
  |      x3,y3   |
  |______________|
 x1,y1
(x1, y1, x2, y2 ) (x3, y3, x4, y4)
x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2

Find the total area covered by two rectilinearrectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum1 = (C - A) * (D - B), sum2 = (H - F) * (G - E);
        if (E >= C || F >= D || B >= H || A >= G) return sum1 + sum2;
        return sum1 - ((min(G, C) - max(A, E)) * (min(D, H) - max(B, F))) + sum2;
    }
};


int computeare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int sum1 = (y2-y1) * (x2-x1)  , sum2 = (y4-y3)*(x4-x3);
    if (x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2)
        return sum1 + sum2 - (min(y4,y2) - max(y3,y1))* (min(x4, x2) - max(x3, x1))

    else
        return sum1 + sum2;
}
