#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> G[5001];
int q[10001],visit[5001],f[5001];
int bfs (int k){
    int front=1,rear=1,i;
    memset(q,0,sizeof(q));
    memset (visit,0,sizeof(visit));
    q[1]=k;
    visit[k]=1;
    while (front<=rear){
          for (i=0;i<G[q[front]].size();i++){
              if (!visit[G[q[front]][i]]){
                 visit[G[q[front]][i]]=1;
                 q[++rear]=G[q[front]][i];
              }
          }
          front++;
    }
    return rear-1;
}             
int main () {
    int n,m,t,i,u,v;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>u>>v;
        G[u].push_back(v);
    }
    for (i=1;i<=5000;i++){
        f[i]=bfs (i);
    }
    cin>>m;
    for (i=1;i<=m;i++){
        cin>>t;
        cout<<G[t].size()<<' '<<f[t]<<endl;
    }
    return 0;
}
