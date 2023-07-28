#include <cstdio>
#include <cmath>

double f(double x){
    return pow(x,5)-15*pow(x,4)+85*pow(x,3)-225*pow(x,2)+274*x-121;
}

int main(){
    double l=1.5,r=2.4,mid;
    while(r-l > 0.00000001){
        mid=(l+r)/2;
        if(f(mid)>0.0)
            l=mid;
        else
            r=mid;
    }
    printf("%.6lf\n",l);
    return 0;
}