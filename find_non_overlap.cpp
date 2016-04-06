tor<int> findnonoverlap(string s, string t){
	vector<int> res;
	if (s.length() == 0 || t.length() == 0)
		return res;
	unordered_map<char, int > tmap;
	for (auto t:s)
			tmap[t]++;
	for (int i=0;i<s.length();i++){
		if (!tmap[s[i]])
			res.push_back(i);
		else{ 
			tmap[s[i]]--;
			if (tmap[s[i]] == 0)
			tmap.erase(s[i]);
		}
	}
	return res;
}
