#include <iostream>
using namespace std;
string x,y;
int main () {
    int nx,ny,t;
    t=10;
    while (t--){
          cin>>x>>y;
          nx=x[x.size()-1]-'0';
          ny=y[y.size()-1]-'0';
          if ((nx%5==2||nx%5==3)&&(ny%5==2||ny%5==3))cout<<"Shadow"<<endl;
          else cout<<"Matrix67"<<endl;
    }
    return 0;
}
