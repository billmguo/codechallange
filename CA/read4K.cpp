
int read4K(char *buf, int n) {
	if (n <= 0)
		return n;
	int i = 0;
	while (left >0 && i < n) {
		buf[i++] = lbuf[curp++%4K];
	}
	if (left == 0)
		curp = 0;
	while(true) {
		if (i >= n)
			return i;
		int bytes = read4k(lbuf);
		if (bytes == 0)
			return i;
		while(i < n && bytes) {
			buf[i++] = lbuf[curp++%4K];
			--bytes;
		}
		left = bytes;
	}
}

class Solution {
public:
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;
    }
private:
    int readPos = 0, writePos = 0;
    char buff[4];
};
