#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int id;
    string name;
    int grade;
};
vector<node> v;

int main(){
    int n,k,id,grade;
    string name;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>id>>name>>grade;
        v.push_back({id,name,grade});
    }
    if(k==1){
        sort(v.begin(),v.end(),[](const node& a,const node& b){
            return a.id<b.id;
        });
    }
    else if(k==2){
        sort(v.begin(),v.end(),[](const node& a,const node& b){
            if(a.name==b.name) return a.id<b.id;
            else return a.name<b.name;
        });
    }
    else{
        sort(v.begin(),v.end(),[](const node& a,const node& b){
            if(a.grade==b.grade) return a.id<b.id;
            else return a.grade<b.grade;
        });
    }
    for(auto x:v){
        printf("%06d ",x.id);
        cout << x.name << ' ' << x.grade << endl;
    }
    return 0;
}