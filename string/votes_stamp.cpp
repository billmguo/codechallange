1. Use sort list to track the votes 
2. Update entry, and swap the entry with the earlist same vo
3. update the map to record the first vote number 

map<int, char> m;
list<pair<char,int>> lm;
for (int i = 0; i < votes.size();i++) {
	int index = lm.find(votes[i]);
	if (index == -1))
		lm.push_back(make_pair(votes[i],1));
		if (!m[1])
			m[1] = votes[i];
	else{
		int ov = lm[index].second;
		lm[index].second++;
		if (m[ov] && lm[index].first! = m[ov])
			swap(lm[index],lm[ov]);
		if (lm[index+1].second == ov)
			m[ov] = lm[index+1].first;
		else
			m.erase(ov);
		if (!m[ov+1])
			m[ov+1] = lm[index].first;
	}
}
