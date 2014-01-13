#include <iostream>
#include <cstdio> 
using namespace std;
struct D {
       int n,l,r,x,y,lazy;
}tree[2000001];
int tot,T;
int _init (int now,int l,int r) {
    tot++;
    tree[now].l=l;
    tree[now].r=r;
    int m=(l+r)/2;
    if (l==r)return 0;
    tree[now].x=tot+1;
    _init (tot+1,l,m);
    tree[now].y=tot+1;
    _init (tot+1,m+1,r);
    return 0;
}
int _insert (int now,int M,int N){
    tree[now].n=tree[now].n==0?N:min(tree[now].n,N);
    if (tree[now].l==tree[now].r)return 0;
    int m=(tree[now].l+tree[now].r)/2;
    if (M<=m){
       _insert (tree[now].x,M,N);
    }
    else {
       _insert (tree[now].y,M,N);
    }
    return 0;
}
int _change (int now,int l,int r,int t,int lazy){
    if (tree[now].l>=l&&tree[now].r<=r){
       tree[now].lazy+=t;
       if (tree[now].n-tree[now].lazy-lazy<0){
          T=false;
       }
       return 0;
    }
    if (tree[now].l==tree[now].r)return 0;
    int L=tree[now].x;
    int R=tree[now].y;
    int m=(tree[now].l+tree[now].r)/2;
    if (l<=m){
       _change (L,l,min(r,m),t,lazy+tree[now].lazy);
    }
    if (r>m){
       _change (R,max(l,m+1),r,t,lazy+tree[now].lazy);
    }
    tree[now].n=min(tree[L].n-tree[L].lazy,tree[R].n-tree[R].lazy);
    return 0;
}   
int main () {
    int n,m,i,l,r,temp,t;
    cin>>n>>m;
    tot=0;
    _init(1,1,n);
    for (i=1;i<=n;i++){
        scanf ("%d",&temp);
        _insert (1,i,temp);
    }
    T=true;
    for (i=1;i<=m;i++){
        scanf ("%d%d%d",&t,&l,&r);
        _change (1,l,r,t,0);
        if (T==false){
           cout<<"-1"<<endl<<i<<endl;
           return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
