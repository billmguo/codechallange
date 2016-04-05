give a sequence of task like ABC mean 3 ifferent tasks and
cold time.

inptu string namespace output the the best -finishing sequeue.
eg. input AAABBB, 2
out AB_AB_AB
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

string taskscheule(string input, int coldtime){
	string res;
	map<char,int> hmap;
	#define pp pair<char,int>
	struct compare  
 	{  
		 bool operator()(const pp& a, const pp& b)  
   		{  
    	   return a.second > b.second;  
		 }  
 	}; 
	priority_queue<pp, vector<pp>,compare> pq;
	
	if (input.size()==0)
		return res;
	int time = 0;
	for (int i=0;i<input.size();i++){
		char ch = input[i];
		hmap[ch]++;
	}
	int i=0;
	for(auto c:hmap){
		pq.push({c.first,0});
	}
	while(!pq.empty()){
		pp item = pq.top();
		if (time >=item.second){
			pq.pop();
			res.push_back(item.first);
			hmap[item.first]--;
			if (hmap[item.first]>0)
				pq.push({item.first,time+coldtime+1});
			if(hmap[item.first]==0)
			{
				hmap.erase(item.first);
			}
		}else
			res.push_back('_');
		time++;
   }
	return res;
}
int main() {
	string input{"AAABBB"};
	string res;
	res = taskscheule(input,2);
	return 0;
}
