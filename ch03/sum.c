// https://wdxtub.com/2016/04/16/thin-csapp-2/
long plus(long x, long y);

void sumstore(long x, long y, long *dest) {
    long t = plus(x,y);
    *dest = t;
}