#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    int x,y;
    int num,color;
    double tilt;
}p[300];
int ans[300];

double cal(Point s,Point a){
    return (a.x-s.x)/sqrt((a.x-s.x)*(a.x-s.x)+(a.y-s.y)*(a.y-s.y));
}

void divide(int left,int right){
    if(left+1>=right)
        return;
    //先找出最下方的点
    sort(p+left,p+right,[](Point A,Point B){return A.y==B.y?A.x<B.x:A.y<B.y;});
    int color=p[left].color;
    for(int i=left+1;i<right;i++)
        p[i].tilt=cal(p[left],p[i]);
    //然后扇形状扫描
    sort(p+left+1,p+right,[](Point A,Point B){return A.tilt>B.tilt;});
    //起始点要设置好
    int s1=1,s2=0;
    for(int i=left+1;i<right;i++){
        if(p[i].color==color)
            s1++;
        else
            s2++;
        if(s1==s2){
            if(color==0)
                ans[p[left].num]=p[i].num;
            else
                ans[p[i].num]=p[left].num;
            divide(left+1,i);
            divide(i+1,right);
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    for(int cas=0;cin>>n;cas++){
        if(cas)
            cout << endl;
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y;
            p[i].color=0;
            p[i].num=i+1;
        }
        for(int i=n;i<2*n;i++){
            cin>>p[i].x>>p[i].y;
            p[i].color=1;
            p[i].num=i-n+1;
        }
        divide(0,2*n);
        for(int i=1;i<=n;i++)
            cout << ans[i] << endl;
    }
    return 0;
}