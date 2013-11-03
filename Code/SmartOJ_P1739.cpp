#include <iostream>
using namespace std;
int G[201][201],num[201],dist[201][201];
int main () {
    int n,i,j,k;
    cin>>n;
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            cin>>G[i][j];
            if (G[i][j]==0&&i!=j)G[i][j]=20000000;
        }
    }
    for (i=1;i<=n;i++){
        cin>>num[i];
    }
    for (k=1;k<=n;k++){
        for (i=1;i<=n;i++){
            for (j=1;j<=n;j++){
                if (G[i][k]+G[k][j]<G[i][j]){
                   G[i][j]=G[i][k]+G[k][j];
                }
            }
        }
    }
    int ansi,ans;
    ans=2147483647;
    for (i=1;i<=n;i++){
        int temp=0;
        for (j=1;j<=n;j++){
            temp+=(G[i][j]*num[j]);
        }
        if (temp<ans){
           ans=temp;
           ansi=i;
        }
    }
    cout<<ansi<<endl<<ans<<endl;
    return 0;
}
