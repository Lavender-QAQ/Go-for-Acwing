#include <iostream>
#include <stack>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=1000010;


char str[2];
int l[maxn],r[maxn],s[maxn],m[maxn],a=-1,b=-1;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        cin>>str;
        if(*str=='I'){
            int x;
            cin>>x;
            if(a<0){
                a++;
                l[a]=x,s[a]=x,m[a]=x;
            }
            else{
                a++;
                m[a]=max(m[a-1],s[a-1]+x),s[a]=s[a-1]+x,l[a]=x;
            }
        }
        else if(*str=='D'){
            if(a>=0)
                a--;
        }
        else if(*str=='L'){
            if(a>=0){
                b++;
                r[b]=l[a];
                a--;
            }
        }
        else if(*str=='R'){
            if(b>=0){
                a++;
                int x=r[b--];
                m[a]=max(m[a-1],s[a-1]+x);
                s[a]=s[a-1]+x;
                l[a]=x;
            }
        }
        else if(*str=='Q'){
            int x;
            cin>>x;
            cout << m[x-1] << endl;
        }
        /*for(int i=0;i<=a;i++)
            cout << "l[" <<i << "]=" << l[i] << endl;*/
    }
    return 0;
}