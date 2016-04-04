extern int read4(char *buf);

class Solution {
public:
    Solution() : buffCnt(0), buffPtr(0) {}

    int read(char *buf, int n) {
        int cnt = 0;
        while(cnt<n){
            if(buffPtr==0)
                buffCnt = read4(buff);
            if(buffCnt==0)  break;
            while(cnt<n && buffPtr<buffCnt)
                buf[cnt++] = buff[buffPtr++];
            if(buffPtr==buffCnt)  buffPtr=0;
        }
        return cnt;
    }

private:
    int buffCnt;
    int buffPtr;
    char buff[5];
};
