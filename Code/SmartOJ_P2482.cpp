#include <iostream>
using namespace std;
const int INF=2147483647;
int f[100001],g[100001],opt[100001];
int main () {
    //freopen ("1.in","r",stdin);
    //freopen ("1.out","w",stdout);
    int n,i;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>f[i];
        f[i]-=i;
        g[i]=INF;
    }
    for (i=1;i<=n;i++){
        int k=lower_bound(g+1,g+n+1,f[i])-g;
        g[k]=f[i];
        opt[i]=k;
    }
    int ans=0;
    for (i=1;i<=n;i++){
        ans=max(ans,opt[i]);
    }
    cout<<n-ans<<endl;
    return 0;
}

        
