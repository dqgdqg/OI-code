#include<stdio.h>
#define LL long long
int pnum, x, y;
int getMultMod(int start, int end, int p) {
    int i, j;
    LL res;
    for (i = start, res = 1, pnum = 0; i <= end; i++) {
        if (i % p == 0) {
            j = i;
            while (j % p == 0) {
                pnum++;
                j /= p;
            }
            res = res * j % p;
        } else {
            res = res * i % p;
        }
    }
    return (int) (res % p);
}
void extend_gcd(int a, int b) {
    int xx;
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    extend_gcd(b, a % b);
    xx = x;
    x = y, y = xx - a / b * y;
}
void solve(int n, int m, int p) {
    int a, b, apnum, bpnum;
    LL res;
    a = getMultMod(n - m + 1, n, p);
    apnum = pnum;
    b = getMultMod(1, m, p);
    bpnum = pnum;
    if (apnum > bpnum) {
        puts("0");
        return;
    } else {
        extend_gcd(b, p);
         res = (LL) x;
         res = (res % p + p) % p;
        res = res * a % p;
        printf("%lld\n", res);
    }
}
int main() {
    int t, n, m, p;
    scanf("%d%d", &n, &m);
    int i,c,summ=0;
    for (i=1;i<=m;i++){
        scanf ("%d",&c);
        summ+=c;
    }
    n=n-summ;
    solve(n-1, m-1, 1000000007);
    return 0;
}
