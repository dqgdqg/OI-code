#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int UP=1,LOW=0;
int m[400001],w[400001],f[400001];
int low[200001],up[200001];
int first,n;
int cmp (const int a,const int b){
    return a>b;
}
int aabs (int a){
    return a<0?-a:a;
}
int init () {
    int i;
    cin>>n;
    for (i=1;i<=n;i++){
        //cin>>m[i];
        scanf ("%d",&m[i]);
    }
    if (m[1]>m[2]){
       //up[++up[0]]=1;
       up[0]++;
       first=UP;
    }
    else {
       //low[++low[0]]=1;
       low[0]++;
       first=LOW;
    }
    for (i=2;i<=n-1;i++){
        if (m[i]>m[i-1]&&m[i]>m[i+1]){
           //up[++up[0]]=i;
           up[0]++;
        }
        if (m[i]<m[i-1]&&m[i]<m[i+1]){
           //low[++low[0]]=i;
           low[0]++;
        }
    }
    if (m[n]>m[n-1]){
       //up[++up[0]]=n;
       up[0]++;
    }
    else {
       //low[++low[0]]=n;
       low[0]++;
    }
    for (i=1;i<=n;i++){
        cin>>w[i];
    }
    sort (w+1,w+n+1,cmp);
    return 0;
}
int work () {
    int up_m,low_m,t,i;
    long long ans=0;
    if (low[0]>up[0]||(low[0]==up[0]&&((first==UP&&up[0]%2==1)||(first==LOW&&low[0]%2==0)))){
       up_m=(up[0]+1)/2;
       low_m=(low[0]+2)/2;
       up[up_m]=1;
       t=2;
       for (i=1;;i++){
           if (up_m+i>up[0])break;
           up[up_m+i]=t++;
           if (up_m-i<1)break;
           up[up_m-i]=t++;
       }
       low[low_m]=1;
       t=2;
       for (i=1;;i++){
           if (low_m-i<1)break;
           low[low_m-i]=t++;
           if (low_m+i>low[0])break;
           low[low_m+i]=t++;
       }
    }
    if (low[0]<up[0]||(low[0]==up[0]&&((first==LOW&&low[0]%2==1)||(first==UP&&up[0]%2==0)))) {
       up_m=(up[0]+2)/2;
       low_m=(low[0]+1)/2;
       up[up_m]=1;
       t=2;
       for (i=1;;i++){
           if (up_m-i<1)break;
           up[up_m-i]=t++;
           if (up_m+i>up[0])break;
           up[up_m+i]=t++;
       }
       low[low_m]=1;
       t=2;
       for (i=1;;i++){
           if (low_m+i>low[0])break;
           low[low_m+i]=t++;
           if (low_m-i<1)break;
           low[low_m-i]=t++;
       }
    }
    if (first==LOW){ 
       t=1;
       for (i=1;i<low[0];i++){
           ans+=aabs(w[n-low[i]+1]-w[up[i]])+aabs(w[up[i]]-w[n-low[i+1]+1]);
       }
       if (low[0]==up[0]){
          ans+=aabs(w[n-low[low[0]]+1]-w[up[up[0]]]);
       }
    }
    else {
       t=1;
       for (i=1;i<up[0];i++){
           ans+=aabs(w[up[i]]-w[n-low[i]+1])+aabs(w[n-low[i]+1]-w[up[i+1]]);
       }
       if (low[0]==up[0]){
          ans+=aabs(w[n-low[low[0]]+1]-w[up[up[0]]]);
       }
    }
    cout<<ans<<endl;
    return 0;
}
        
int main () {
    init();
    work();
    return 0;
}
