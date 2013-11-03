#include <iostream>
using namespace std;
bool a[1001][1001];
int h[1001][1001];
char ch;
int f[1001][1001],l[1001],r[1001];
int ans;
int main () {
    //freopen ("1.in","r",stdin);
    //freopen ("1.out","w",stdout);
    int n,m,i,j;
    cin>>n>>m;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            cin>>ch;
            if (ch=='F'){
               a[i][j]=0;
            }
            if (ch=='R'){
               a[i][j]=1;
            }
        }
    }
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            if (a[i][j]==0){
               h[i][j]=h[i-1][j]+1;
            }
            else {
               h[i][j]=0;
            }
            //cout<<h[i][j]<<' ';
        }//cout<<endl;
    }
    ans=0;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            l[j]=j;
            while (l[j]>=2&&h[i][j]<=h[i][l[j]-1]){
                  l[j]=l[l[j]-1];
            }
        }
        for (j=m;j>=1;j--){
            r[j]=j;
            while (r[j]<=m-1&&h[i][j]<=h[i][r[j]+1]){
                  r[j]=r[r[j]+1];
            }
        }
        for (j=1;j<=m;j++){
            if (h[i][j]*(r[j]-l[j]+1)>ans){
               ans=h[i][j]*(r[j]-l[j]+1);
            }
        }
    }
    cout<<ans*3<<endl;
    return 0;
}
