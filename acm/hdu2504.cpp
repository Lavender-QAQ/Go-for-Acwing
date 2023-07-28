#include <iostream>
using namespace std;

int gcd(int a,int b) {
    return b==0?a:gcd(b,a%b);
}

int main() {
    int n,a,b,c;
    cin>>n;
    while (n--) {
        cin>>a>>b;
        c = 2*b;
        while (gcd(a, c) != b)
            c+=b;
        cout << c << endl;
    }
    return 0;
}

