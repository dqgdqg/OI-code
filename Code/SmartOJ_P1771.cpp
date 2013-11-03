#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int hei,bai;
string map[15];
int p[9]={0,1,1,1,0,-1,-1,-1,0};
int q[9]={0,0,-1,1,1,0,1,-1,-1};
int work (int x,int y,int xx,int yy,char c){
    int temp=0;
    while (x>=0&&y>=0&&x<15&&y<15&&map[x][y]==c){
          x+=xx;
          y+=yy;
          temp++;
          if (temp==5)return 1;
    }
    return 0;
}
int main () {
    int t,i,j,k;
    cin>>t;
    while (t--){
    hei=bai=0;
    for (i=0;i<15;i++)cin>>map[i];
    for (i=0;i<15;i++){
        for (j=0;j<15;j++){
            if (map[i][j]=='O'){
               for (k=1;k<=8;k++){
                   if (work (i,j,p[k],q[k],'O'))bai=1;
               }
            }
            if (map[i][j]=='X'){
               for (k=1;k<=8;k++){
                   if (work (i,j,p[k],q[k],'X'))hei=1;
               }
            }
        }
    }
    if (bai==hei)cout<<"I don't know."<<endl;
    if (bai>hei)cout<<"O win."<<endl;
    if (hei>bai)cout<<"X win."<<endl;
    scanf ("\n");
    }
    return 0;
}
