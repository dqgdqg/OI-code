#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
string s[100001],ans;
int cmp_up (const string a,const string b){
    return a<b;
}
int cmp_low (const string a,const string b){
    return a>b;
}
int main () {
    int n,m,i;
    cin>>n>>m;
    for (i=1;i<=n;i++){
        cin>>s[i];
    }
    if (m==1){
       sort (s+1,s+n+1,cmp_up);
    }
    else {
       sort (s+1,s+n+1,cmp_low);
    }
    int tmp;
    for (i=1;i<=n;i++){
        scanf ("%d",&tmp);
        if (tmp<=s[i].size())ans+=s[i][tmp-1];
    }
    cout<<ans<<endl;
    return 0;
}
