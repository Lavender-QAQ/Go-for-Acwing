#include <iostream>
#include <cmath>
using namespace std;

int n,ans,res,cnt;

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
                res+=mid-L;
            }
        }
        for(int i=l;i<r;i++)
            a[i]=t[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n&&n){
        ans=0;
        int in;
        int *a=new int[n*n+10];
        int *t=new int[n*n+10];
        cnt=0;
        for(int i=0;i<n*n;i++){
            cin>>in;
            if(in!=0)
                a[cnt++]=in;
        }
        res=0;
        merge_sort(a,0,n*n-1,t);
        ans=res;
        cnt=0;
        for(int i=0;i<n*n;i++){
            cin>>in;
            if(in!=0)
                a[cnt++]=in;
        }
        res=0;
        merge_sort(a,0,n*n-1,t);
        if((ans&1)==(res&1))
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }
    return 0;
}