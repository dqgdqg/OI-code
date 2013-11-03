#include <iostream>
using namespace std;
int biao[11];
int tou (int k){
    int i,s;
    k--;
    s=1;
    for (i=1;i<=k;i++){
        s*=10;
    }
    return s;
} 
int wei (int k){
    int i,s;
    k--;
    s=9;
    for (i=1;i<=k;i++){
        s=s*10+9;
    }
    return s;
}
int dan (int m,int k){
    int n=tou(k)+m-1;
    cout<<n;
    n/=10;
    while (n){
       cout<<n%10;
       n/=10;
    }
    cout<<endl;
}
int shuang (int m,int k){
    int n=tou(k)+m-1;
    cout<<n;
    while (n){
       cout<<n%10;
       n/=10;
    }
    cout<<endl;
}   
int main () {
    int n,i;
    cin>>n;
    n++;
    for (i=1;i<=9;i++){
        biao[i]=(wei(i)-tou(i)+1)*2;
    }
    int m=n;
    for (i=1;i<=9;i++){
        m-=biao[i];
        if (m<=0)break;
    }
    m+=biao[i];
    if (m<=biao[i]/2){
       dan (m,i);
    }
    else {
       m-=biao[i]/2;
       shuang (m,i);
    }
    return 0;
}
