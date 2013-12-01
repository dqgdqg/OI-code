#include <iostream>
using namespace std;
#define LL long long
const int INF=2147483647;
LL map[101][101],visit[101],dist[101];
int dij (int n) {
    LL i,j,mind,minu;
    for (i=1;i<=n;i++){
        dist[i]=INF;
    }
    dist[1]=0;
    for (i=2;i<=n;i++){
        mind=INF;
        for (j=1;j<=n;j++){
            if (dist[j]<mind&&!visit[j]){
               mind=dist[j];
               minu=j;
            }
        }
        visit[minu]=1;
        for (j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[minu]+map[minu][j]);
        }
    }
    return dist[n];
}     
int main () {
    int n,m,i,u,v,w,j;
    while (1){
          cin>>n>>m;
          if (!n&&!m)break;
          for (i=1;i<=n;i++){
              for (j=1;j<=n;j++){
                  if (i!=j)map[i][j]=INF;
              }
          }
          memset(visit,0,sizeof(visit));
          memset(dist,0,sizeof(dist));
          for (i=1;i<=m;i++){
              cin>>u>>v>>w;
              map[u][v]=map[v][u]=w;
          }
          cout<<dij(n)<<endl;
    }
    return 0;
}

          
