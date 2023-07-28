#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ss[110];

struct man{
    string name;
    int age,money;
};

vector<man> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,age,money,cnt,a,b;
    string s;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s>>age>>money;
        v.push_back({s,age,money});
    }
    sort(v.begin(),v.end(),[](const man& a,const man&b){
        if(a.money==b.money&&a.age==b.age)
            return a.name<b.name;
        else if(a.money==b.money)
            return a.age<b.age;
        else return a.money>b.money;
    });
    vector<man> t;
    for(int i=0;i<v.size();i++){
        if(ss[v[i].age]<100){
            t.push_back(v[i]);
            ss[v[i].age]++;
        }
    }
    int p=0;
    for(int i=1;i<=m;i++){
        p=0;
        cin>>cnt>>a>>b;
        //cout << a << ' ' << b << endl;
        cout << "Case #" << i << ":" << endl;
        for(int j=0;j<t.size();j++)
            if(t[j].age>=a&&t[j].age<=b){
                cout << t[j].name << ' ' << t[j].age << ' ' << t[j].money << endl;
                p++;
                if(p==cnt) break;
            }
        if(p==0) cout << "None" << endl;
    }
    return 0;
}