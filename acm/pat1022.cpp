#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string,vector<int>> title,author,keyword,publisher,year;

int main(){
    int n,id,x;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>id;
        //cout << id << endl;
        cin.ignore();
        getline(cin,s);
        //cout << s << endl;
        title[s].push_back(id);
        getline(cin,s);
        //cout << s << endl;
        author[s].push_back(id);
        getline(cin,s);
        //cout << s << endl;
        string t="";
        for(auto c:s){
            if(c==' ') keyword[t].push_back(id),t="";
            else t+=c;
        }
        keyword[t].push_back(id);
        getline(cin,s);
        //cout << s << endl;
        publisher[s].push_back(id);
        getline(cin,s);
        //cout << x << endl;
        year[s].push_back(id);
    }
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        cout << s << endl;
        int op=s[0]-'0';
        s=s.substr(3,s.length()-3);
        switch(op){
            case 1:{
                auto v=title[s];
                if(v.size()==0) puts("Not Found");
                else{
                    sort(v.begin(),v.end());
                    for(auto k:v)
                        printf("%07d\n",k);
                }
                break;
            }
            case 2:{
                auto v=author[s];
                if(v.size()==0) puts("Not Found");
                else{
                    sort(v.begin(),v.end());
                    for(auto k:v)
                        printf("%07d\n",k);
                }
                break;
            }
            case 3:{
                auto v=keyword[s];
                if(v.size()==0) puts("Not Found");
                else{
                    sort(v.begin(),v.end());
                    for(auto k:v)
                        printf("%07d\n",k);
                }
                break;
            }
            case 4:{
                auto v=publisher[s];
                if(v.size()==0) puts("Not Found");
                else{
                    sort(v.begin(),v.end());
                    for(auto k:v)
                        printf("%07d\n",k);
                }
                break;
            }
            case 5:{
                auto v=year[s];
                if(v.size()==0) puts("Not Found");
                else{
                    sort(v.begin(),v.end());
                    for(auto k:v)
                        printf("%07d\n",k);
                }
                break;
            }
            default:break;
        }
    }
    return 0;
}