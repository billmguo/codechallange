class NestedIterator{
public:
	NestedIterator(vector<NestedInteger> &nestedlist){
		begins.push(nestedlist.begin()));
		ends.push(nestedlist.end());
	}
	int next(){
		hasNext();
		return (begins.top())->getInteger():
		begins.top()++;	
	}
	bool hasNext(){
		while(begins.size()){
			if (begins.top() == ends.top()){
				begins.pop();
				ends.pop();
			}else{
				auto x = begins.top();
				if (x->isInteger())
					return true;
				begins.top()++;
				begins.push(x->getlist().begin());
				ends.push(x->getlist().end());
			}
		}
	}
};
