/*function: 将n用2的指数表示，使得指数表达式的个数最少 
output : int num（指数的最少个数）*/
int MinBinnaryRepresent(unsigned int num)
{
	int count = 0;
	int len = 0;
	while (num != 0)
	{
		if ((num & 0x1) == 0)
			count+=(len>=2)?2:len;
		else
			len++;
		num = num >> 1;
	}

	count+=(len>=2)?2:len;
	return count;
}
