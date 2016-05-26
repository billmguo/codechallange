/*give a dir and dir string, 3E mean move E 3 
D mean erase the previous move*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pp;

void getpoint(pp &p,string dir){
	unordered_map<char, pp> move;
	move['N'] = {0,1};
	move['E'] = {1,0};
	move['S'] = {0,-1};
	move['W'] = {-1,0};
	pp old = {0,0};
	pp newPoint;
	pp olddir;
	int len = dir.size();
	int sum = 1;
	int num = 1;

	for (int i = 0 ; i < len; i++) {
		cout << sum << num << endl;
		if (move.count(dir[i])){	
			p.first  = p.first + sum*move[dir[i]].first;
			p.second =  p.second + sum*move[dir[i]].second;
			cout << newPoint.first <<"*"<< newPoint.second <<  endl;
			cout << i << endl;
			olddir = move[dir[i]]; 
		}

		if (isdigit(dir[i]) && move.count(dir[i+1]) && (i + 1 < len))
			 sum += dir[i] - '0' - 1;

		if (isdigit(dir[i]) && dir[i+1] == 'D' && (i+1) < len)
			num += dir[i] -'0' - 1;

		if (dir[i] == 'D') {
			p.first -= olddir.first * num;
			p.second -= olddir.second * num;
		}
	}
}
int main() {
	// your code goes here
	pp start{0,0};
	getpoint(start,"EEDD");
	cout<<start.first <<" "<< start.second <<endl;
	return 0;
}
