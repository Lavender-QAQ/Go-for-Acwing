#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct stu{
    string name,id;
    int grade;
};

vector<stu> m,f;

int main(){
    int n,grade;
    string name,id,gender;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name>>gender>>id>>grade;
        if(gender[0]=='M') m.push_back({name,id,grade});
        else f.push_back({name,id,grade});
    }
    sort(m.begin(),m.end(),[](const stu& a,const stu& b){
        return a.grade<b.grade;
    });
    sort(f.begin(),f.end(),[](const stu& a,const stu& b){
        return a.grade>b.grade;
    });
    bool ff=true,mm=true;
    if(f.size()==0||(f.size()>1&&f[0].grade==f[1].grade))
        cout << "Absent" << endl,ff=false;
    else cout << f[0].name << ' ' << f[0].id << endl;
    if(m.size()==0||(m.size()>1&&m[0].grade==m[1].grade))
        cout << "Absent" << endl,mm=false;
    else cout << m[0].name << ' ' << m[0].id << endl;
    if(!mm||!ff) cout << "NA" << endl;
    else cout << f[0].grade-m[0].grade << endl;
    return 0;
}