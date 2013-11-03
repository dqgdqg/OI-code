#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned long long a[100001],r[100001];
int cmp (const unsigned long long p,const unsigned long long q){
    return a[p]>a[q];
}
int main () {
    unsigned long long n,i;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>a[i];
        r[i]=i;
    }
    sort (r+1,r+n+1,cmp);
    unsigned long long sum1,sum2;
    sum1=a[r[1]]*(n-1);
    sum2=a[r[1]]*(n-2)+a[r[2]]*(n-2);
    cout<<max(sum1,sum2)<<endl;
    return 0;
}
