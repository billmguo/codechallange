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


Example:

Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
	
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int num : nums) {
                if (num & (1 << i)) ++cnt;
            }
            res += cnt * (n - cnt);
        }
        return res;
    }
};
