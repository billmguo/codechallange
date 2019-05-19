 void letterCombinationsDFS(int n, vector<string>& dict, int level, string out, vector<string>& res) {
        if (level == n) {res.push_back(out); return;}
        string str = dict[level];
        for (int i = 0; i < str.size(); ++i) {
            letterCombinationsDFS(n, dict, level + 1, out + str[i], res);
        }
   }
