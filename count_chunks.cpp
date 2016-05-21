int countchunks(string s, int start, int end, int count){
	if (s.length()==0)
		return 0;
	int prestart = 0, preend = 0;
	int i = 1;
	int start = 0, end = s.length()-1;

	while(start < end){
		string  left = s.substr(start,i);
		string  right = s.substr(end, i);
		if (left == right)
		{
			i++;
		}else{ 
			start = start + i ;
			end = end - i;
			count++;
			break;
		}		
	}	
	count *= 2;
	if (left == right)
		count += 1;
	return count;
}
