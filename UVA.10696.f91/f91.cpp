#include <cstdio>
#include <cstring>

int main(){
    int n;
    int arr[1000001];
    memset(arr,0,sizeof(arr));
    for(int i = 1000000;i>0;--i){
            arr[i] = i>=101?i-10:arr[arr[i+11]];
    }
    while(scanf("%d",&n)&& n){
        printf("f91(%d) = %d\n",n,arr[n]);
    }
    return 0;
}
