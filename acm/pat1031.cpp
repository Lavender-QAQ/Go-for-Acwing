#include <iostream>
using namespace std;

char ch[1010][1010];

int main(){
    string s;
    cin>>s;
    int n=s.size()+2;
    int a=n/3,b=n/3+n%3,k=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            ch[i][j]=' ';
    for(int i=0;i<a;i++)
        ch[i][0]=s[k++];
    for(int i=1;i<b-1;i++)
        ch[a-1][i]=s[k++];
    for(int i=a-1;i>=0;i--)
        ch[i][b-1]=s[k++];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++)
            cout << ch[i][j];
        cout << endl;
    }
    return 0;
}