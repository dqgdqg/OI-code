#include <iostream>
using namespace std;
int v[201],c[201];
int f[201][1001][21];
const int INF=2147483647;
int main () {
    int k,V,n,i,j,p;
    cin>>k>>V>>n;
    for (i=0;i<=n;i++){
        for (j=0;j<=V;j++){
            for (p=0;p<=k;p++){
                f[i][j][p]=-INF;
            }
        }
    }
    for (i=1;i<=n;i++){
        cin>>v[i]>>c[i];
        f[i][v[i]][1]=c[i];
    }
    for (i=1;i<=n;i++){
        for (j=0;j<=V;j++){
            for (p=0;p<=k;p++){
                f[i][j][p]=max(f[i][j][p],f[i-1][j][p]);
                if (p-1>=0&&j-v[i]>=0){
                   f[i][j][p]=max(f[i][j][p],f[i-1][j-v[i]][p-1]+c[i]);
                }
            }
        }
    }
    if (f[n][V][k]>0)cout<<f[n][V][k]<<endl;
    else cout<<"impossible"<<endl;
    return 0;
}
