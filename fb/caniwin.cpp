explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.

bool canIwin(int mx, int total) {
	if (mx >= total)
		return true;
	if (mx*(mx + 1)/2  < total)
		return false;
	unodered_map<int, bool> m;
	return canIwin(mx, total, 0, m);
}

bool canwin(int len, int total, int used, unodered_map<int, bool> &m) {
	if (m.count(used))
		return m[used];
	for (int i = 0; i < len; i++) {
		int cur = 1<<i;
		if (cur & used == 0) {
			if (total <= i + 1 || !canwin(len, total - (i + 1), cur|used,m)) {
				m[used] = true;
				return true;
			}
		}
	}
	m[used]= false;
	return false;
}
