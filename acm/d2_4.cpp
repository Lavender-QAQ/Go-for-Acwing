#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int ch[30];

int main(){
    int T;
    while(cin>>T){
        int n;string s;
        while(T--){
            cin>>n>>s;
            memset(ch,0, sizeof(ch));
            for(int i=0;i<s.length();i++)
                ch[s[i]-'a']++;
            priority_queue<int,vector<int>,greater<int> > que;
            for(int i=0;i<30;i++)
                if(ch[i])
                    que.push(ch[i]);
            int sum=0,ans=0,flag=1;
            if(que.size()==1){
                ans=que.top();
                flag=0;
            }
            while(que.size()>1&&flag){
                int t1=que.top();que.pop();
                int t2=que.top();que.pop();
                sum=t1+t2;
                ans+=sum;
                que.push(sum);
            }
            if(ans<=n)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}
