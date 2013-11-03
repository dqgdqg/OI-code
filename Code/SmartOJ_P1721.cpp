#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF=2147483647;
int a[100001];
int cmp (const int p,const int q){
    return p<q;
}
int aabs (int n){
    return n<0?-n:n;
}
int main () {
    int n,m,i,tmp,ans=0;
    cin>>n>>m;
    for (i=1;i<=n;i++){
        cin>>a[i];
    }
    sort (a+1,a+n+1,cmp);
    for (i=1;i<=m;i++){
        cin>>tmp;
        int k=lower_bound(a+1,a+n+1,tmp)-a;
        int minn;
        if (k==1)minn=aabs(a[k]-tmp);
        else minn=min(aabs(a[k-1]-tmp),aabs(a[k]-tmp));
        ans+=minn;
    }
    cout<<ans<<endl;
    return 0;
}
