#include <iostream>
using namespace std;
string str[2001];
int f[2001];
int main () {
    int n,i,j;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>str[i];
    }
    f[1]=1;
    for (i=2;i<=n;i++){
        f[i]=1;
        for (j=1;j<i;j++){
            if (str[i].find(str[j])==0){
               f[i]=max(f[i],f[j]+1);
            }
        }
    }
    int ans=0;
    for (i=1;i<=n;i++){
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}
