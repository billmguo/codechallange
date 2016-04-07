int strStr(string haystack, string needle){
	int hlen = haystack.size();
	int nlen = needle.size();
	vector<int> next(26,nlen+1);
	int i,j;
	for(int i=0;i<nlen;i++){
		next[needle[i]-'a'] = nlen - i;	
	}
	int result = -1;
	int jump ;
	int pos = 0;
	while(hlen - pos >= nlen){
		if (haystack.substr(pos,len2) == needle){
			result = pos;
			return result;
		}else{
			jump = next[haystack[pos+nlen] - 'a'];
			pos += jump;	
		}
	}
	return -1;
		
}
