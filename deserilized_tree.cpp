nNoddeTree* deserialzie(string s, int childsize{
	stringstrem sub(s);
	return deserialzie_s(sub,childsize);
}
nNodeTree* deserialzie_s(stringstrem &in,int size){
	char temp
	in>>temp;
	if (temp == '#')
		return nullptr;
	else{
		nNodeTree* newnode = new nNodeTree(temp-'a');
		for (int i=0;i<size;i++){
			nNodeTree *pnode = deserialzie_s(s,in,size);
			newnode.push_back(pnode);
		}
	}
}
