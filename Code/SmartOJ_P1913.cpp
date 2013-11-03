#include <iostream>
using namespace std;
bool p[1024][1024],q[1024];
int c[1024];
long long f[11][1024][101];
int _ (int k){
    int i,t;
    t=0;
    for (i=0;i<=9;i++){
        if ((1&(k>>i))==t&&t==1){
           return false;
        }
        t=(1&(k>>i));
    }
    int s=0;
    for (i=0;i<=9;i++){
        s+=(1&(k>>i));
    }
    c[k]=s;
    return true;
}
int __ (int x,int y){
    return ((x&y)||(x&(y>>1))||(y&(x>>1)))^1;
}
int main () {
    int n,K,m;
    int i,j,k,jj;
    cin>>n>>K;
    m=(1<<n);
    for (i=0;i<m;i++){
        q[i]=_(i);
    }
    for (i=0;i<m;i++){
        if (q[i])
        for (j=0;j<m;j++){
            if (q[j]){
               p[i][j]=__(i,j);
               //if (p[i][j])cout<<i<<' '<<j<<endl;
            }
        }
    }
    for (j=0;j<m;j++)f[1][j][c[j]]=1;
    for (i=2;i<=n;i++){
        for (j=0;j<m;j++){
            if (q[j])
            for (jj=0;jj<m;jj++){
                if (p[j][jj])
                for (k=c[j];k<=K;k++){
                    f[i][j][k]+=f[i-1][jj][k-c[j]];
                }
            }
        }
    }
    long long ans=0;
    for (j=0;j<m;j++)ans+=f[n][j][K];
    cout<<ans<<endl;
    return 0;
}
