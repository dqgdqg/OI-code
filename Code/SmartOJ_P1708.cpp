#include <iostream>
#include <algorithm>
using namespace std;
int a[100001],b[100001],visita[100001],visitb[100001];
int cmp (const int p,const int q){
    return p<q;
}
int main () {
    int n,i,j,m,ans=0;
    cin>>n;
    for (i=1;i<=n;i++)cin>>a[i];
    for (i=1;i<=n;i++)cin>>b[i];
    sort (a+1,a+n+1,cmp);
    sort (b+1,b+n+1,cmp);
    for (i=1;i<=n;i++){
        int k=lower_bound (b+1,b+n+1,a[i])-b;
        for (;k>=1;k--){
            if (visitb[k]==0&&b[k]<a[i]){
               visitb[k]=visita[i]=1;
               ans+=2;
               break;
            }
        }
    }
    j=1;
    for (i=1;i<=n;i++){
        while (visitb[j])j++;
        if (visita[i])continue;
        if (a[i]==b[j]){
           ans++;
           j++;
        }
    }                 
    cout<<ans<<endl;
    return 0;
}
