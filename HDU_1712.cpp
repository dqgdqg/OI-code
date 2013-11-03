#include <iostream>
#include <string.h>
using namespace std;
int f[101][101],c[101][101];
int main () {
    int sub,day,i,j,k;
    while (1){
          cin>>sub>>day;
          if (!sub&&!day)break;
          memset (f,0,sizeof(f));
          for (i=1;i<=sub;i++){
              for (j=1;j<=day;j++){
                  cin>>c[i][j];
              }
          }
          for (i=1;i<=sub;i++){
              for (j=0;j<=day;j++){
                  f[i][j]=f[i-1][j];
                  for (k=1;k<=j;k++){
                      f[i][j]=max(f[i][j],f[i-1][j-k]+c[i][k]);
                  }
              }
          }
          cout<<f[sub][day]<<endl;
    }
    return 0;
}
