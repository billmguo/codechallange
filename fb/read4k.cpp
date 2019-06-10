int read(char *buf, int sz) {
	int ck = sz/4K; n = sz%n;
	for (int i = 0; i < ck; i++) {
		int t = read4k(buf);
		if (t < 0)
			return i * 4K;
	}
	int start = ck * 4K;
	if (n == 0)
		return sz;
	for (int i = 0; i < n; i++) {
		if (readp == writep) {
			writep = read4K(lbuf);
			readp = 0;
			if (writep)
				return i + start;
		}else
			buf[start + i] = lbuf[readp++];
	}
	return sz;
}
