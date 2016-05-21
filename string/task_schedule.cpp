#include <iostream>
#include <queue>
#include <map>
using namespace std;

int count_task_schedule(string &task,int interval) {
	map<char, int> m;
	for (int i = 0;i < task.size();i++)
		m[task[i]]++;
	queue<pair<char,int>> q;
	for (auto a:m){
		q.push({a.first,a.second});
	}
	int n = 0, t = 0;
	map<char, int>  s;
	string seq;
	while(n < task.size()) {
		pair<char,int> cur = q.front();
		if (!s.count(cur.first) || t >= s[cur.first]){
			q.pop();
			seq += cur.first;
			n++;
			s[cur.first] = t + interval;
			if (--cur.second > 0) 
				q.push({cur.first,cur.second});
		}
		seq+=" ";
		t++;
	}
	cout<<seq<<endl;
	return t;
}
int main() {
	string task = "ABBABBC";
	int intv = 3;
	int res = count_task_schedule(task,intv);
	cout << res<< endl;
	// your code goes here
	return 0;
}
