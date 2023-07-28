#include <iostream>
using namespace std;

int main(){
    int n,ta=-1,tb=-1;
    string a,b,s1,s2;
    cin>>n>>a>>b;
    int k=0;
    for(int i=0;i<a.length()&&a[i]=='0';i++) k++;
    a=a.substr(k,a.length()-k);
    k=0;
    for(int i=0;i<b.length()&&b[i]=='0';i++) k++;
    b=b.substr(k,b.length()-k);
    for(int i=0;i<a.length();i++)
        if(a[i]=='.') ta=i;
        else s1+=a[i];
    for(int i=0;i<b.length();i++)
        if(b[i]=='.') tb=i;
        else s2+=b[i];
    if(ta==-1) ta=(int)a.length();
    if(tb==-1) tb=(int)b.length();
    if(ta==1&&a[0]=='0') ta=0;
    if(tb==1&&b[0]=='0') tb=0;
    while(s1.length()<n) s1.push_back('0');
    while(s2.length()<n) s2.push_back('0');
    while(s1.length()>n) s1.pop_back();
    while(s2.length()>n) s2.pop_back();
    if(ta!=tb||s1!=s2){
        printf("NO ");
        cout << "0." << s1 << "*10^" << ta << " 0." << s2 << "*10^" << tb << endl;
    }
    else{
        printf("YES ");
        cout << "0." << s1 << "*10^" << ta << endl;
    }
    return 0;
}