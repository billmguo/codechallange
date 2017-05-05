int TestandSet(int *x) {
    register int temp = *x;
    *x = 1;
    return temp
}

void exchange(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


typedef int SpinLock;

void InitLock(SpinLock *L)
{   *L = 0; }

void Lock(SpinLock *L)
{   while (TestAndSet(L)) 
        ;
}
void initlock(Spinlock *s){
	*s = 0;
}
void Lock (SpinLock *L) {
           int m = 1;
           do {
              Exchange(&m, s);
           } while (m == 1);
}
void UnLock(SpinLock *L)
{   *L = 0; }
