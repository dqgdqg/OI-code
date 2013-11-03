#include <iostream>
#include <algorithm>
using namespace std;
int x[100001],y[100001];
int cmp (const int a,const int b){
    return a<b;
}
int main () {
    int n,i;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    sort (x+1,x+n+1,cmp);
    sort (y+1,y+n+1,cmp);
    long long minx,miny,maxx,maxy;
    minx=x[1];
    maxx=x[n];
    miny=y[1];
    maxy=y[n];
    cout<<(maxx-minx)*(maxy-miny)<<endl;
    return 0;
}
