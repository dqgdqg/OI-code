#include <cstdio>
#include <cstring>
using namespace std;
int c[100001],d[100001],a[20001];
int cc[100001],dd[100001];
int lowbit (int x){
    return x&-x;
}
int add (int x,int d){
    while (x<=100000){
          c[x]+=d;
          x+=lowbit(x);
    }
    return 0;
}
int sum (int x){
    int s=0;
    while (x>0){
          s+=c[x];
          x-=lowbit(x);
    }
    return s;
}
int main () {
    int t;
    scanf ("%d",&t);
    while (t--){
    int i,j,n;
    scanf ("%d",&n);
    memset (a,0,sizeof(a));
    memset (cc,0,sizeof(cc));
    memset (dd,0,sizeof(dd));
    for (i=1;i<=n;i++){
        scanf ("%d",&a[i]);
    }
    memset (c,0,sizeof(c));
    for (i=1;i<=n;i++){
        add(a[i],1);
        cc[i]=sum(a[i]-1);
    }
    memset (c,0,sizeof(c));
    for (i=n;i>=1;i--){
        add(a[i],1);
        dd[i]=sum(a[i]-1);
    }
    long long ans=0;
    for (i=2;i<=n-1;i++){
        ans+=(long long)cc[i]*(n-i-dd[i])+(long long)dd[i]*(i-cc[i]-1);
    }
    printf ("%I64d\n",ans);
    }
    return 0;
}
