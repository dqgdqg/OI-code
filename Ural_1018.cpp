#include <iostream>
using namespace std;
struct D {
       int l,r,x;
}tree[101];
int map[101][101],n,q;
int dp[101][101];
int dps (int k){
    int i;
    for (i=1;i<=n;i++){
        if (map[k][i]){
           if (tree[k].l)tree[k].r=i;
           else tree[k].l=i;
           tree[i].x=map[k][i];
           map[k][i]=map[i][k]=0;
           dps (i);
        }
    }
    return 0;
}
int init() {
    int i,j,a,b,tmp;
    cin>>n>>q;
    for (i=1;i<=n-1;i++){
        cin>>a>>b>>tmp;
        map[a][b]=map[b][a]=tmp;
    }
    for (i=1;i<=n;i++){
        if (map[1][i]){
           if (tree[1].l)tree[1].r=i;
           else tree[1].l=i;
           tree[i].x=map[1][i];
           map[1][i]=map[i][1]=0;
           dps(i);
        }
    }
    return 0;
}
int treedp (int k,int q){
    if (k==0)return -2147483647;
    if (q==0)return dp[k][q]=tree[k].x;
    if (dp[k][q]>0)return dp[k][q];
    int i;
    dp[k][q]=max(treedp(tree[k].l,q-1)+tree[k].x,treedp(tree[k].r,q-1)+tree[k].x);
    for (i=0;i<=q-2;i++){
        dp[k][q]=max(treedp(tree[k].l,q-i-2)+treedp(tree[k].r,i)+tree[k].x,dp[k][q]);
    }
    return dp[k][q];
}
int main () {
    //freopen ("1.in","r",stdin);
    //freopen ("1.out","w",stdout);
    init();
    int ans=treedp(1,q);
    cout<<ans<<endl;
    return 0;
}
