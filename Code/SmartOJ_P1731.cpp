#include <iostream>
#include <stdio.h>
using namespace std;
struct tree {
   int x,y;
   int l,r;
   int n;
}f[400001];
int tot;
int build (int l,int r){
    int now=tot;
    tot++;
    f[now].l=l;
    f[now].r=r;
    f[now].n=0;
    if (l<r){
       f[now].x=tot;
       build (l,(l+r)/2);
       f[now].y=tot;
       build ((l+r)/2+1,r);
    }
    return 0;
}
int insert (int now,int l,int r){
    if (f[now].l==l&&f[now].r==r){
       f[now].n=1;
       return 0;
    }
    if (f[now].l<=l&&f[now].r>=r&&f[now].n==1){
       return 0;
    }
    if (l<=f[f[now].x].r){
       insert (f[now].x,l,min(f[f[now].x].r,r));
    }
    if (r>=f[f[now].y].l){
       insert (f[now].y,max(f[f[now].y].l,l),r);
    }
    //if (f[f[now].x].n==1&&f[f[now].y].n==1)f[now].n=1;
    return 0;
}
int getsum (int now){
    if (f[now].n==1)return f[now].r-f[now].l+1;
    if (f[now].l==f[now].r)return 0;
    return getsum (f[now].x)+getsum(f[now].y);
}
int main () {
    int n,m,a,b;
    cin>>n>>m;
    tot=1;
    build(1,n);
    while (m--){
       scanf ("%d%d",&a,&b);
       insert (1,a,b);
       printf ("%d\n",n-getsum(1));
    }
    return 0;
}
