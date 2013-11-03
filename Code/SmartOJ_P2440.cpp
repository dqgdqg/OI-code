#include <iostream>
using namespace std;
int a[501],b[501],f[501][501];
int main () {
    int n,m,maxx,mins,i,j,k,ii,jj;
    cin>>n>>m;
    maxx=0;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            cin>>a[j];
            b[m-j+1]=a[j];
        }
        for (ii=1;ii<=m;ii++){
            for (jj=1;jj<=m;jj++){
                f[ii][jj]=max(f[ii-1][jj],f[ii][jj-1]);
                if (a[ii]==b[jj]){
                   f[ii][jj]=max(f[ii-1][jj-1]+1,f[ii][jj]);
                }
            }
        }
        maxx=max(maxx,m-f[m][m]);
    }
    cout<<maxx*n<<endl;
    return 0;
}
