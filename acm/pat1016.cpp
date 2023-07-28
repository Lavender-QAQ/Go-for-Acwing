#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int maxn=10010;
typedef pair<int,double> P;

double fare[100],day_money;
unordered_set<string> s;

struct info{
    string name;
    int state,month,day,hour,minute,sum;
    void ver(){
        sum=day*24*60+hour*60+minute;
    }
    bool operator < (const info& p) const{
        if(p.name==name) return sum<p.sum;
        else return name<p.name;
    }
}a[maxn];

P cal(info a){
    P ans;
    ans.first=ans.second=0;
    for(int i=0;i<a.day;i++){
        ans.first+=24*60;
        ans.second+=day_money;
    }
    for(int i=0;i<a.hour;i++){
        ans.first+=60;
        ans.second+=fare[i]*60;
    }
    ans.first+=a.minute;
    ans.second+=fare[a.hour]*a.minute;
    return ans;
}

int main(){
    int n;
    day_money=0;
    for(int i=0;i<24;i++)
        cin>>fare[i],fare[i]*=0.01,day_money+=60*fare[i];
    cin>>n;
    for(int i=0;i<n;i++){
        string name,state;
        cin>>name;
        a[i].name=name;
        scanf("%d:%d:%d:%d",&a[i].month,&a[i].day,&a[i].hour,&a[i].minute);
        cin>>state;
        if(state=="on-line") a[i].state=1;
        else a[i].state=0;
        a[i].ver();
    }
    sort(a,a+n);
    double sum=0;
    int cnt;
    double ans;
    P p1,p2;
    for(int i=1;i<n;i++){
        if(a[i].name==a[i-1].name&&a[i].state==0&&a[i-1].state==1){
            if(!s.count(a[i].name)){
                if(sum!=0)
                    printf("Total amount: $%.2lf\n",sum),sum=0;
                s.insert(a[i].name);
                cout << a[i].name << ' ';
                printf("%02d\n",a[i].month);
            }
            p1=cal(a[i-1]);
            p2=cal(a[i]);
            cnt=p2.first-p1.first;
            ans=p2.second-p1.second;
            sum+=ans;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",a[i-1].day,
                    a[i-1].hour,a[i-1].minute,a[i].day,a[i].hour,a[i].minute,
                   cnt,ans);
        }
    }
    if(sum!=0)
        printf("Total amount: $%.2lf\n",sum);
    return 0;
}