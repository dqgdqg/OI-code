#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M=200001,N=100001;
int n,m,u[M],v[M],c[M],r[M],l[N],ru[N],chu[N];
double p[M],pp[N];
int cmp (const int a,const int b){
    if (u[a]==u[b])return v[a]<v[b];
    return u[a]<u[b];
}
int tuopu (int x){
    if (u[x]==n)return 0;
    int o=r[x],i;
    for (i=x;u[r[i]]==u[r[x]];i++){
        int e=r[i];
        p[e]=pp[u[e]]*(1/double(chu[u[e]]));
        pp[v[e]]+=pp[u[e]]*(1/double(chu[u[e]]));
        ru[v[e]]--;
    }
    for (i=x;u[r[i]]==u[r[x]];i++){
        int e=r[i];
        if (!ru[v[e]]){
           tuopu(l[v[e]]);
        }
    }
    return 0;
}
int main () {
    int i;
    cin>>n>>m;
    for (i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>c[i];
        r[i]=i;
        ru[v[i]]++;
        chu[u[i]]++;
    }
    sort (r+1,r+m+1,cmp);
    for (i=1;i<=m;i++){
        int e=r[i];
        if (!l[u[e]])l[u[e]]=i;
    }
    pp[1]=1;
    tuopu(l[1]);
    double ans=0;
    for (i=1;i<=m;i++){
        ans+=c[i]*p[i];
        //cout<<pp[i]<<' ';
    }
    printf ("%.2f\n",ans);
    return 0;
}
