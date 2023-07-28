
#include <iostream>
#include <map>
#include <string>
#include <stack>
using namespace std;
typedef pair<int,string> mypair;
map<int,string> mymap1;
map<int,string> mymap2;
string transform(long long i)
{
    mymap1.insert(mypair(0,"零"));
    mymap1.insert(mypair(1,"壹"));
    mymap1.insert(mypair(2,"贰"));
    mymap1.insert(mypair(3,"叁"));
    mymap1.insert(mypair(4,"肆"));
    mymap1.insert(mypair(5,"伍"));
    mymap1.insert(mypair(6,"陆"));
    mymap1.insert(mypair(7,"柒"));
    mymap1.insert(mypair(8,"捌"));
    mymap1.insert(mypair(9,"玖"));

    mymap2.insert(mypair(1,"拾"));
    mymap2.insert(mypair(2,"佰"));
    mymap2.insert(mypair(3,"仟"));
    mymap2.insert(mypair(4,"万"));
    mymap2.insert(mypair(8,"亿"));
    int count=-1,j=0,k=0;
    int yi=100000000;
    int wan=10000;
    string result;
    stack<int> stak;
    if(i>yi)
    {
        j=i/yi;
        while(j)
        {
            stak.push(j%10);
            ++count;
            j/=10;
        }
        while(!stak.empty())
        {
            k=stak.top();
            stak.pop();

            while(k==0&&!stak.empty()&&stak.top()==0)
            {
                --count;
                stak.pop();
            }
            if(k==0&&stak.empty()) break;
            result+=mymap1[k];
            if(count>0&&k!=0)
            {
                result+=mymap2[count];
                --count;
            }
            else
                --count;
        }
        count=-1;
        result+=mymap2[8];
    }

    //万位
    if(i>wan)
    {
        j=i%yi;
        j=j/wan;
        while(j)
        {
            stak.push(j%10);
            ++count;
            j/=10;
        }
        while(!stak.empty())
        {
            k=stak.top();
            stak.pop();

            while(k==0&&!stak.empty()&&stak.top()==0)
            {
                --count;
                stak.pop();
            }
            if(k==0&&stak.empty()) break;
            result+=mymap1[k];
            if(count>0&&k!=0)
            {
                result+=mymap2[count];
                --count;
            }
            else --count;
        }
        count=-1;
        if(i%yi)
            result+=mymap2[4];
    }
    //万位以下
    if(i>0)
    {
        j=i%wan;
        while(j)
        {
            stak.push(j%10);
            ++count;
            j/=10;
        }
        while(!stak.empty())
        {
            k=stak.top();
            stak.pop();

            while(k==0&&stak.empty()&&stak.top()==0)
            {
                --count;
                stak.pop();
            }
            if(k==0&&!stak.empty()) break;
            result+=mymap1[k];
            if(count>0&&k!=0)
            {
                result+=mymap2[count];
                --count;
            }
            else --count;
        }
    }
    return result;
}


int main()
{
    long double a=0;
    long long x;
    string result;
    while(a!=-1)
    {
        cin>>a;
        x=(long long)a;
        long long b=(long long)(a*100)%100;
        result=transform(x);
        cout<<result;
        if(b==0) cout << "元整" << endl;
        else{
            int x=b/10,y=b%10;
            if(x>0) cout << mymap1[x] << "角";
            if(y>0){
                cout << mymap1[y] << "分";
            }
            cout << endl;
        }
    }
    return 0;
}