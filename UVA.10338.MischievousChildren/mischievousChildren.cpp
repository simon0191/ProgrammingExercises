#include <cstdio>
#include <cstring>
#include <climits>
#define UL unsigned long long
const int SIZE = 'z'-'a'+1;
int main(){
    UL fact[21];
    fact[0] = fact[1] = 1;
    for(int i = 2;i<21;++i){
        fact[i] = i*fact[i-1];
    }
    int cases;
    char buff[30];
    int arr[SIZE];
    UL ans;
    scanf("%d",&cases);
    for(int i = 0;i<cases;++i){
        memset(arr,0,sizeof(arr));
        scanf("%s",buff);
        int j;
        for(j = 0;buff[j];++j){
            arr[buff[j]-'A']++;
        }
        ans = fact[j];
        for(j=0;j<SIZE;++j){
            if(arr[j]>1){
                ans/=fact[arr[j]];
            }
        }
        printf("Data set %d: %llu\n",i+1,ans);
    }
}
