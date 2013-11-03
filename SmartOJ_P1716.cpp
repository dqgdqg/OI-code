#include <iostream>
#include <cmath>
using namespace std;
int main () {
    int n,k,ans=0;
    cin>>n>>k;   
    k++;n--;
    long long s=1;
    while (s<n){
          s*=k;
          ans++;
    }
    cout<<ans<<endl;
}
