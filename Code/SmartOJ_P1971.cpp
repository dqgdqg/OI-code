#include <iostream>
#include <cstring>
using namespace std;
int map[1001][1001],visit[1001],f[1001];
int n,m;
int find (int k){
    int i;
    for (i=1;i<=m;i++){
        if (map[k][i]&&!visit[i]){
           visit[i]=1;
           if (f[i]==0||find(f[i])){
              f[i]=k;
              return 1;
           }
        }
    }
    return 0;
}
int main () {
    int k,u,v,i,ans;
    cin>>n>>m>>k;
    for (i=1;i<=k;i++){
        cin>>u>>v;
        map[u][v]=1;
    }
    ans=0;
    for (i=1;i<=n;i++){
        memset (visit,0,sizeof (visit));
        if (find(i)){
           ans++;
        }
    }
    cout<<n+m-ans<<endl;
    return 0;
}
