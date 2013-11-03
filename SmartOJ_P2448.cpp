#include <iostream>
#include <cstdio>
using namespace std;
short f[5001][5001];
int main () {
    //freopen ("1.in","r",stdin);
    //freopen ("1.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int i,j;
    f[0][0]=1;
    for (i=1;i<=n;i++){
        for (j=0;j<=k;j++){
            f[i][j]=(((i-j)*f[i-1][j-1])%2009+((j+1)*f[i-1][j])%2009)%2009;
            //cout<<f[i][j]<<' ';
        }//cout<<endl;
    }
    cout<<f[n][k]<<endl;
    return 0;
}
