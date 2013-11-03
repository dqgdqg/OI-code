#include <iostream>
using namespace std;
int f[10001][8],a[10001];
int _ (int k){
    int s=0,i;
    for (i=0;i<3;i++){
        s+=((k>>i)&1);
    }
    return s;
}
int main () {
    int n,i,k,kk;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>a[i];
    }
    for (k=0;k<=3;k++){
        if (_(k)==a[1]){
           f[1][k]++;
        }
    }
    for (i=2;i<=n-1;i++){
        for (k=0;k<8;k++){
            if (_(k)==a[i])
            for (kk=0;kk<8;kk++){
                if (((k&6)>>1)==(kk&3)){
                   f[i][k]+=f[i-1][kk];
                }
            }
        }
    }
    for (k=0;k<=3;k++){
        if (_((k<<1))==a[n])
        for (kk=0;kk<8;kk++){
            if (k==(kk&3)){
               f[n][k<<1]+=f[n-1][kk];
            }
        }
    }
    int ans=0;
    for (k=0;k<8;k++)ans+=f[n][k];
    cout<<ans<<endl;
    return 0;
}
