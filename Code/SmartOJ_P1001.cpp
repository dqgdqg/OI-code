#include <iostream>
using namespace std;
int t[10001];
int x[10001],y[1001],i;
void Add( int c[], const int a[], const int b[] ){
     int i;
     t[0]=(a[0]>b[0]?a[0]:b[0]);
     for( i=1; i<=t[0];i++){
          t[i]+=a[i]+b[i];
          t[i+1]+=t[i]/10;
          t[i]%=10;
     }
     if( t[t[0]+1])++t[0];
     for (i=0;i<=t[0];i++)c[i]=t[i];
}
int main () {
    string a,b;
    cin>>a>>b;
    x[0]=a.size();
    y[0]=b.size();
    for (i=x[0];i>=1;i--){
        x[i]=a[x[0]-i]-'0';
    }
    for (i=y[0];i>=1;i--){
        y[i]=b[y[0]-i]-'0';
    }
    int z[1001];
    Add (z,x,y);
    while (!z[z[0]])z[0]--;
    for (i=z[0];i>=1;i--){
        cout<<z[i];
    }
    if (z[0]==-1)cout<<0<<endl;
    return 0;
}
