#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
  
   int find_min_intervals(vector<Interval> &intv, Interval &target) {
 	sort(intv.begin(), intv.end(), [](const Interval &a, const Interval &b) {return a.start < b.start;});
 	int res = 0;
 	int curt = target.start;
 	int i =  0, max_step = 0;
 	while (i < intv.size() && curt < target.end) {
 		cout<<"prec"<<curt<<endl;
 		while (i < intv.size() && intv[i].start <= curt) {
 			max_step = max(max_step, intv[i].end);
 			i++;
 		}
 		curt = max_step;
 		res++;
 		if (intv[i].start > max_step || max_step >= target.end) break;
 		cout<<res<<endl;
 	}
 	cout<<curt<<endl;
 	
 	if (curt >= target.end)
 		return res;
 	else
 		return 0;
 }
 
int main() {
	// your code goes here
	vector<Interval> intv{{-1, 9}, { 1, 10}, {0, 3}, {9, 10}, {3, 14}, {2, 9}, {10, 16},{17,18}};
	Interval target{2,18};
	int res = find_min_intervals(intv, target);
	cout<<res<<endl;
	return 0;
}
