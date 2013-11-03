#include <iostream>
#include <cstdio>
using namespace std;
long long f[1000001],F[1000001];
int g[1000001];
int main () {
    int a,b,t;
    scanf ("%d",&t);
    int i,j;
    for (i=2;i<=1000000;i++)g[i]=i;
    for (i=2;i<=1000;i++){
        if (g[i]==i){
           for (j=2;j<=1000000/i;j++){
               g[i*j]=i;
           }
        }
    }
    for (i=2;i<=1000000;i++){
        g[i]==i?F[i]=i:F[i]=F[i/g[i]]+g[i];
        f[i]=f[i-1]+F[i];
    }
    while (t--){
       scanf ("%d%d",&a,&b);
       cout<<(f[b]-f[a-1])%1919<<endl;
    }
    return 0;
}
