#include <iostream>
#include <cmath>
using namespace std;

int sa[26],sb[26],sc[26],sd[26];

int main(){
    string a,b,c,d;
    string s[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cin>>a>>b>>c>>d;
    int f_day=0,h,m;
    string day;
    for(int i=0;i<min(a.length(),b.length());i++){
        if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G'&&f_day==0){
            day=s[a[i]-'A'];
            f_day=1;
        }
        else if(a[i]==b[i]&&f_day&&((a[i]>='A'&&a[i]<='N')||(a[i]>='0'&&a[i]<='9'))){
            if(a[i]>='A'&&a[i]<='N') h=a[i]-'A'+10;
            else h=a[i]-'0';
            break;
        }
    }
    for(int i=0;i<min(c.length(),d.length());i++){
        if(c[i]==d[i]&&((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z'))){
            m=i;
            break;
        }
    }
    cout << day;
    printf(" %02d:%02d\n",h,m);
    return 0;
}