#include <iostream>
using namespace std;
int cifang[21]={0,1,16,81,256,625,1296,2401,4096,6561,10000,14641,20736,28561,38416,50625,65536,83521};
int f[100001];
const int INF=2147483647;
int min (int a,int b){
    return a<b?a:b;
}
int main () {
    int m,n;
    cin>>m;
    for (int i=1;i<=m;i++){
        f[i]=INF;
        for (int j=1;j<=17;j++){
            if (cifang[j]>i)break;
            f[i]=min(f[i-cifang[j]]+1,f[i]);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
