#include <iostream>
using namespace std;
int fx[101],fy[101];
int out () {
    int gx[101],gy[101];
    int i,x=1,y=100,ans=0,ming;
    for (i=1;i<=100;i++){
        gx[i]=fx[i];
        gy[i]=fy[i];
    }
    while (!gx[x])x++;
    while (!gy[y])y--;
    while (1){
          ans=max(x+y,ans);
          ming=min(gx[x],gy[y]);
          gx[x]-=ming;
          gy[y]-=ming;
          while (!gx[x]&&x<=100)x++;
          while (!gy[y]&&y>=1)y--;
          if (y<1&&x>100)break;
    }
    cout<<ans<<endl;
    return 0;
} 
int main () {
    int n,i,x,y;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>x>>y;
        fx[x]++;
        fy[y]++;
        out();
    }
    return 0;
}
