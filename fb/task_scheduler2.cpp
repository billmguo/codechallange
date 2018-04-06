#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int task_scheduler2(string task, int k) {
	unordered_map<int, int> m;
	int t = 0;
	
	for (int i = 0; i < task.size(); i++) {
		int cur = task[i];
		if (!m.count(cur)) {
			m[cur] = t + k + 1;
		} else {
			int last = m[cur];
			if (t >= last)
				m[cur] = t;
			else
			    i--;
		}
		t++;
	}
	return t;
}
int task_scheduler(string task, int k) {
	unordered_map<int, int> m;
	int t = 0;
	for (int i = 0; i < task.size();i++) {
		if (!m.count(task[i]) || (t - m[task[i]] > k && m.count(task[i]))){
			m[task[i]] = t;
			t++;
		} else if (t - m[task[i]] < k && m.count(task[i])) {
				t = m[task[i]] + k + 2;
				m[task[i]] = t - 1;
		 }
	}
	return t ;
}

int main() {
	// your code goes here
	int res = task_scheduler("ABBABAA", 3);
	cout << res<<endl;
	return 0;
}
