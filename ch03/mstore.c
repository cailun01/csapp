// https://wdxtub.com/2016/04/16/thin-csapp-2/
long mult2(long x, long y);

void sumstore(long x, long y, long *dest) {
    long t = mult2(x,y);
    *dest = t;
}
