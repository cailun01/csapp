void multstore (long x, long y, long *dest);
long mult2(long a, long b);

// multstore 函数
void multstore (long x, long y, long *dest)
{
    long t = mult2(x, y);
    *dest = t;
}
// mult2 函数,被multstore调用
long mult2(long a, long b)
{
    long s = a * b;
    return s;
}