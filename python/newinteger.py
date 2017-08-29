def newInteger(n):
	ans = ''
	while n:
		ans += str((n % 9))
		n /= 9
	print ans
	return int(ans[::-1])
print newInteger(11)
