#include <iostream>
using namespace std;

int main(){
    int T,m,n;
    cin>>T;
    while(T--) {
        cin >> n >> m;
        if (n % (m + 1) == 0)
            cout << "second" << endl;
        else
            cout << "first" << endl;
    }
    return 0;
}
