nclude <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
using namespace std;

string rearrangechar(string str, int k){
    if (str.empty()||str.size() < k)
        return str;
    int len = str.size();
    string res="";
    typedef pair<char,pair<int,int>> Node;
    map<char,Node> m;
    for (int i=0; i<len;i++){
        m[str[i]].first = str[i];
        m[str[i]].second.first++;
    }
    queue<Node> q;
    struct mycompare{
        bool operator()(const Node &a, const Node &b){
            if (a.second.first != b.second.first)
                return a.second.first > b.second.first? 0:1;
            return a.first - b.first? 1:0;
        }
    };
    priority_queue<Node,vector<Node>,mycompare> pq;
    for (auto &node: m)
        pq.push(node.second);

    for (int i = 0;i<len;i++){
        if (!q.empty() && (q.front().second.second + k < i)){
            pq.push(q.front());
            q.pop();
        }
        if (pq.empty()){
            return "invalid";
        }
        Node cur = pq.top();
        pq.pop();
        cur.second.second = i;
        cur.second.first --;
        res += cur.first;
        if (cur.second.first) 
        	q.push(cur);
    }
    return res;
}
int main() {
	// your code goes here
	string s{"aaaaabbbcccddee"};
	string res = rearrangechar(s, 2);
	cout<<res<<endl;
	return 0;
}
