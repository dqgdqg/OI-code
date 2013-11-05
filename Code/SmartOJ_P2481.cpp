#include <iostream>
using namespace std;
int f[100001],a[100001];
bool b[100001];
int main () {
    int n,q,i,j,l,r;
    cin>>n>>q;
    for (i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0]=1;
    for (i=1;i<=n;i++){
        b[a[i]]=1;
        for (j=f[i-1]+1;j<=n;j++){
            if (b[a[j]]&&j!=i){
               f[i]=j-1;
               break;
            }
            b[a[j]]=1;
        }
        if (j>n)f[i]=n;
        b[a[i]]=0;
    }
    //for (i=1;i<=n;i++)cout<<f[i]<<' ';cout<<endl;
    for (i=1;i<=q;i++){
        cin>>l>>r;
        if (f[l]>=r){
           cout<<"Yes"<<endl;
        }
        else {
           cout<<"No"<<endl;
        }
    }
    return 0;
}
