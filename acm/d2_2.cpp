#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,c;
    cout << "输入人数：",cin>>n;
    int* a=new int[n+10];
    cout << "输入每个人的重量：";
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << "输入船的最大容量：",cin>>c;
    sort(a,a+n);
    int i=0,j=n-1,sum=0;
    while(i<=j){
        if(i==j) {
            sum++;
            break;
        }
        if(a[i]+a[j]>c) {
            j--;
            sum++;
        }
        else{
            i++,j--;
            sum++;
        }
    }
    cout << "最少需要" << sum << "条船" << endl;
    return 0;
}