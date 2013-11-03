#include <iostream>
#include <algorithm>
using namespace std;
int n,m,u[100001],v[100001],c[100001],r[100001];
int f[100001];
int cmp (const int a,const int b){
    return c[a]>c[b];
}
int find (int k){
    return f[k]==k?k:find(f[k]);
}
int work (int k){
    int i,j,s=1;
    for (i=1;i<=n;i++){
        f[i]=i;
    }
    f[u[r[k]]]=v[r[k]];
    for (i=k+1;i<=m;i++){
        int e=r[i];
        int fu=find(u[e]),fv=find(v[e]);
        //cout<<fu<<endl<<fv<<endl;
        if (fu==fv)continue;
        f[fu]=fv;
        s++;
    }
    return s;
}
int main () {
    int i,j,ans;
    cin>>n>>m;
    cout<<n-1<<' ';
    for (i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>c[i];
        r[i]=i;
    }
    sort (r+1,r+m+1,cmp);
    int ll,rr;
    ll=1;rr=m;
    while (ll<rr){
          int m=(ll+rr)/2+1;
          if (work(m)<n-1){
             rr=m-1;
          }
          else {
             ll=m;
          }
    }
    //cout<<ll<<endl<<rr<<endl;
    cout<<c[r[ll]]<<endl;
    /*for (i=1;i<=m;i++){
        int e=r[i];
        int tmp=work(i);
        if (tmp<n-1){
           cout<<ans<<endl;
           return 0;
        }
        ans=c[e];
    }*/
    return 0;
}
