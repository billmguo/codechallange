/*CCBBAAA -> ABABACABC，就是输出相邻字母不能相同的string，这题要用到heap第一题估计是用贪心法，
每次把出现最多的字母解
*/
unordered_map<char, int> map;
string noSameNeighbor(string & s){
        string ans = "";
        for (char c : s)
                map[c]++;              
        
        auto comp = [](char char1, char char2){return map[char1] < map[char2];};
        priority_queue<char, vector<char>, decltype<comp> pq(comp);

        for (auto &p : map)
                pq.push(p.first);

        while (!pq.empty()){
                char c = pq.top();
                pq.pop();
                if (pq.empty()){
                        ans += c;
                        break;
                }
                char d = pq.top();
                pq.pop();
                ans += c;
                ans += d;
                map[c]--;
                map[d]--;
                if (map[c] > 0) pq.push(c);
                if (map[d] > 0) pq.push(d);
        }

        return ans;
}
