#include <iostream>
using namespace std;

long long ans;

void merge_sort(int *a,int l,int r,int *t){
    if(r-l>1){
        int mid=(l+r)>>1;
        int L=l,R=mid,pos=l;
        merge_sort(a,l,mid,t);
        merge_sort(a,mid,r,t);
        while(L<mid||R<r){
            if(R>=r||(L<mid&&a[L]<=a[R])){
                t[pos++]=a[L++];
            }
            else{
                t[pos++]=a[R++];
                ans+=mid-L;
            }
        }
        for(int i=l;i<r;i++)
            a[i]=t[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n&&n){
        int *a=new int[n+10];
        int *t=new int[n+10];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ans=0;
        merge_sort(a,0,n,t);
        cout << ans << endl;
    }
    return 0;
}
