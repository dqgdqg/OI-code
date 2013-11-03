#include <iostream>
using namespace std;
long long f,f1,f2,f3;
int main () {
    int n,i;
    cin>>n;
    f=1;
    f1=1;
    f2=0;
    f3=0;
    for (i=1;i<=n;i++){
        f=(f1+4*f2+2*f3)%1000000007;
        f3=f2;
        f2=f1;
        f1=f;
    }
    cout<<f<<endl;
    return 0;
}
