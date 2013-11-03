#include <iostream>
#include <algorithm>
using namespace std;
int a[10001],b[10001],v[10001];
int r[10001],d[10001],g[10001];
int cmp (const int p,const int q){
    if (a[p]==a[q]){
       return b[p]<b[q];
    }
    return a[p]<a[q];
}
int main () {
    int n;
    cin>>n;
    int i,j;
    for (i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>v[i];
        r[i]=i;
    }
    sort (r+1,r+n+1,cmp);
    for (i=1;i<=n;i++){
        int e=r[i];
        d[e]=1;
        g[e]=v[e];
        for (j=1;j<i;j++){
            int u=r[j];
            if (b[u]<=b[e]&&d[u]+1>d[e]){
               d[e]=d[u]+1;
               g[e]=g[u]+v[e];
            }
            if (b[u]<=b[e]&&d[u]+1==d[e]){
               g[e]=max(g[e],g[u]+v[e]);
            }
        }
    }
    int ansd=0,ansg=0;
    for (i=1;i<=n;i++){
        int e=r[i];
        if (d[e]>ansd)ansd=d[e];
    }
    for (i=1;i<=n;i++){
        int e=r[i];
        if (d[e]==ansd&&g[e]>ansg)ansg=g[e];
    }
    cout<<ansd<<endl<<ansg<<endl;
    return 0;
}
