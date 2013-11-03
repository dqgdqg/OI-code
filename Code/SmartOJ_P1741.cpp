#include <iostream>
#include <algorithm>
using namespace std;
const int INF=2147483647;
int f[1000001],g[1000001],opt[1000001];
int main () {
    int n,i,ans;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>f[i];
        g[i]=INF;
    }
    for (i=1;i<=n;i++){
        int k=lower_bound(g+1,g+n+1,f[i])-g;
        opt[i]=k;
        g[k]=f[i];
    }
    ans=0;
    for (i=1;i<=n;i++){
        ans=max(ans,opt[i]);
    }
    cout<<n-ans<<endl;
    return 0;
}
