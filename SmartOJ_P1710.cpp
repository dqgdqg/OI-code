#include <iostream>
#include <algorithm>
using namespace std;
struct D {
   int a,t,x;
}num[101];
int f[101][10001];
int cmp (const D p,const D q){
    if (p.a==q.a){
       if (p.t==q.t)return p.x>q.x;
       else return p.t<q.t;
    }
    else return p.a<q.a;
}
int main () {
    int T,n,i,e,j,sumx=0;
    cin>>T>>n;
    for (i=1;i<=n;i++){
        cin>>num[i].a>>num[i].t>>num[i].x;
        sumx+=num[i].x;
    }
    sort (num+1,num+n+1,cmp);
    for (i=0;i<=n;i++){
        for (j=0;j<=T;j++){
            f[i][j]=sumx;
        }
    }
    for (i=1;i<=n;i++){
        for (j=0;j<=T;j++){
            f[i][j]=min(f[i][j],f[i-1][j]);
            if (j-num[i].t+1>=num[i].a){
               f[i][j]=min(f[i][j],f[i-1][j-num[i].t]-num[i].x);
            }
        }
    }
    cout<<f[n][T]<<endl;
    return 0;
}
