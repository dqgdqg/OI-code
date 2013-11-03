#include <iostream>
using namespace std;
int n;
int num[5001];
int mul (int k){
    int len=num[0],jin=0,t[5001],i;
    for (i=1;i<=num[0];i++){
        t[i]=(num[i]*k+jin)%10;
        jin=(num[i]*k+jin)/10;
    }
    t[0]=num[0];
    if (jin!=0){
       t[0]++;
       t[t[0]]=jin;
    }
    for (i=0;i<=t[0];i++){
        num[i]=t[i];
    }
    return 0;
}
int main () {
    cin>>n;
    int x3,x2,i;
    for (x3=n/3;x3>=1;x3--){
        if ((n-x3*3)%2==0){
           x2=(n-x3*3)/2;
           break;
        }
    }
    num[0]=1;
    num[1]=1;
    while (x3--){
          mul(3);
    }
    while (x2--){
          mul(2);
    }
    cout<<num[0]<<endl;
    for (i=num[0];i>=1;i--){
        if (num[0]-i+1==101)break;
        cout<<num[i];
    }
    cout<<endl;
    return 0;
}
