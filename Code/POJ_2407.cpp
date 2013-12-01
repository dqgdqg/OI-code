#include <iostream>
#include <cmath>
using namespace std;
int euler (int n){
    int m=(int)sqrt(n+0.5);
    int ans=n,i;
    for (i=2;i<=m;i++){
        if (n%i==0){
           ans=ans/i*(i-1);
           while (n%i==0)n/=i;
        }
    }
    if (n>1)ans=ans/n*(n-1);
    return ans;
}
int main () {
    int n;
    while (1){
          cin>>n;
          if (!n)break;
          cout<<euler(n)<<endl;
    }
    return 0;
}
