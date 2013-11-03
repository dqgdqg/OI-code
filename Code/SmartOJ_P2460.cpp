#include <iostream>
#include <cstdio>
using namespace std;
long long gcd (long long a,long long b){
     if (b==0)return a;
     return gcd(b,a%b);
}
long long aabs (long long a){
     return a<0?-a:a;
}
int main () {
    long long x1,y1,x2,y2,temp;
    while (cin>>x1>>y1>>x2>>y2){
          long long dx=x1-x2,dy=y1-y2;
          if (x1==x2&&y1==y2){
             printf ("Error\n");
             continue;
          }
          if (dx==0){
             //printf ("x=%lld\n",x1);
             printf ("Error\n");
             continue;
          }
          if (dy==0){
             //printf ("y=%lld\n",y1);
             printf ("Error\n");
             continue;
          }
          if (dy%dx==0){
             if (dy/dx==1){
                printf ("y=x");
             }
             else if (dy/dx==-1){
                printf ("y=-x");
             }
             else {
                printf ("y=%lldx",dy/dx);
             }
          }
          else {
             temp=gcd(aabs(dy),aabs(dx));
             //cout<<(((dx>0)&&(dy<0))||((dx<0)&&(dy>0)))<<endl;
             printf ("y=");
             if (((dx>0)&&(dy<0))||((dx<0)&&(dy>0)))printf ("-");
             printf ("%lld/%lldx",aabs(dy)/temp,aabs(dx)/temp);
          }
          long long t=y1*dx-x1*dy;
          if (t==0){
             printf ("\n");
             continue;
          }
          if (t%dx==0){
             if ((dx>0&&t>0)||(dx<0&&t<0))printf ("+");
             printf ("%lld",t/dx);
          }
          else {
             temp=gcd(aabs(t),aabs(dx));
             if ((dx>0&&t<0)||(dx<0&&t>0))printf ("-");
             else printf ("+");
             printf ("%lld/%lld",aabs(t)/temp,aabs(dx))/temp;
          }
          printf ("\n");
    }
    return 0;
}
