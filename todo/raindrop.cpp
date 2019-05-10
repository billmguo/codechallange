
struct interval {
    double left=0;
    double right=0.01;
    bool isWet() {
        return left>=right;
    }
};

vector<interval> sidewalk(100,interval());
int cnt=0, wetCnt=0, idx;

void simulate() {
	while (wetCnt < 100) {
		++cnt;
		double p = double(rand())/RAND_MAX;
		double l = p - 0.005;
		double r = p + 0.005;
		if (l >= 0) {
			idx = l/0.01;
			if (!sidewalk[idx].isWet()) {
				ir = l - idx * 0.01;
				if (ir < sidewalk[idx].right) {
					sidewalk[idx].right = ir;
					if (sidewalk[idx].iswet())
						++wecnt;
				}
			}
		}
		if (r <= 1) {
			idx = r/0.01;
			if (!sidewalk[idx].iswet) {
				il = r - idx*0.01;
				if (il > sidewalk[idx].left) {
					sidewalk[idx].left = il;
					if (sidewalk[idx].iswet())
						++wecnt;
				}
			}
		}

	}
}
