#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int proc(int n){
    long double a = log10(n);
    long double b = log10(2);
    long double resp = a/b;
    return resp;
}
int proc(int vec[],int n,int r){
    int left = 0;
    int right = r;
    int med = (left+right)/2;
    while(vec[right]-vec[left] >= vec[left]*2){
        if(vec[med] > n){
            right = med;
        }
        else{
            left = med;
        }
        med = (left+right)/2;
    }
    return left;
}
int f(int n){
    int x = 1;
    for(int i = 0;i<n;++i){
        x<<=1;
    }
    return x;
}
int main(){
    int n,cont,cas=1;
    int vec[1000];
    vec[0] = 1;
    int right;
    for(right =1;right<11;++right){
        vec[right] = ((vec[right-1])*2);
    }
    while(scanf("%d",&n) && n >=0){
        if(n<=1)printf("Case %d: %d\n",cas++,0);
        else {
            //int r = proc(vec,n,right);
            int r = proc(n);
            if(f(r) != n){
                r++;
            }
            printf("Case %d: %d\n",cas++,r);
        }
    }
    return 0;
}
