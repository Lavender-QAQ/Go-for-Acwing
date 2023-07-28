#include <iostream>
#include <queue>
using namespace std;

int n;

struct node{
    int x,y;
    friend bool operator < (node a,node b){
        return a.x==b.x?a.y>b.y:a.x<b.x;
    }
    node(int x,int y){
        this->x=x;
        this->y=y;
    }
};

int main(){
    while(cin>>n){
        string s;int a,b,c=0;
        priority_queue<node> que[3];
        while(n--) {
            cin >> s;
            if (s == "IN") {
                c++;
                cin >> a >> b;
                que[a - 1].push(node(b, c));
            } else {
                cin >> a;
                if (!que[a - 1].empty()) {
                    node p = que[a - 1].top();
                    que[a - 1].pop();
                    cout << p.y << endl;
                } else
                    cout << "EMPTY" << endl;
            }
        }
    }
    return 0;
}
