#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct tree {
       int u;
       int v;
       int l;
};
int fa[200001],a[200001];
tree map[200001];
int cmp (const int i,const int j){
    return map[i].l<map[j].l;
}
int find (int k){
    if (fa[k]==k)return k;
    return find(fa[k]);
}
int main () {
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        fa[i]=i;
    }
    for (int i=1;i<=m;i++){
        scanf ("%d%d%d",&map[i].u,&map[i].v,&map[i].l);
    }
    long long ans;
    ans=0;
    for (int i=1;i<=m;i++){
        a[i]=i;
    }
    sort (a+1,a+m+1,cmp);
    int summ=0,flag=0;
    int e,fau,fav;
    for (int i=1;i<=m;i++){
        e=a[i];
        fau=find(map[e].u);
        fav=find(map[e].v);
        if (fau!=fav){
           ans+=map[e].l;
           fa[fav]=fau; //大家可以尝试着写成fa[fau]=fav;再提交
           summ++;
        }
    }
    if (summ==n-1){
       cout<<ans<<endl;
    }
    else {
       summ=0;
       int temp=find(k);
       for (int i=1;i<=n;i++){
           if (find(i)==temp)summ++;
       }
       cout<<n-summ<<endl;
    }
    return 0;
}
