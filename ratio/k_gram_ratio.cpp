/*K gram ratio, intersection/union, we can also use tire*/
#nclude <iostream>
#include <map>
using namespace std;

float kgramratio(string &sa,string &sb,int k) {
	if (sa.empty()||sb.empty())
		return 0;
	int ka = sa.size() - k + 1;
	int kb = sb.size() - k + 1;
	map<string,int> m;
	for (int i = 0; i < ka; i++) {
		string tmp = sa.substr(i,k);
		m[tmp]++;
	}

	int inters = 0;
	for (int i = 0; i < kb; i++) {
		string tmp = sb.substr(i,k);
		if (!m.count(tmp))
			continue;
		inters++;
		int count = m[tmp] - 1;
		if (count == 0)
			m.erase(tmp);
		else
			m[tmp] = count;
	}
	int unc = ka + kb - inters;
	return inters/float(unc);
}

int main() {
	// your code goes here
	string sa = "aba";
	string sb = "tabab";
	int k =3;
	float res = kgramratio(sa,sb,k);
	cout<<res<<endl;
	return 0;
}
