#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int f[100001];
int ff[100001];
int b[100001];
int opt[100001];
int main () {
    freopen ("1.in","r",stdin);
    freopen ("1.out","w",stdout);
    while (true){
    int n,i,j;
    cin>>n;
    if (!n)break;
    f[0]=-1;
    for (i=1;i<=n;i++){
        f[i]=b[i]=opt[i]=0;
        scanf ("%d",&f[i]);
        if (f[i]==f[i-1]+1)b[i]=1;
    }
    int nn;
    nn=0;
    for (i=1;i<=n;i++){
        if (b[i]==1)continue;
        nn++;
        ff[nn]=f[i];
    }
    int g[100001];
    for (i=1;i<=nn;i++){
        g[i]=2147483647;
    }
    for (i=1;i<=nn;i++){
        int k=lower_bound(g+1,g+n,ff[i])-g;
        opt[i]=k;
        g[k]=ff[i];
    }
    int maxx=0;
    for (i=1;i<=nn;i++){
        if (opt[i]>maxx)maxx=opt[i];
    }
    cout<<nn-maxx<<endl;
    }
    return 0;
}
