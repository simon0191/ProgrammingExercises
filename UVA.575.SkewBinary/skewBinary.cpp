#include <cstdio>
#include <cstring>

int f2pow(int pow){
    int resp = 1;
    resp<<=pow;
    return resp;
}
int main(){
    char buff[1000000];
    int size,pow,num,ans;
    char* pt;
    while(scanf("%s",buff) && strcmp(buff,"0")){
        size = strlen(buff);
        pow = f2pow(size);
        ans = 0;
        for(pt = buff;*pt;++pt){
            num = (*pt)-'0';
            if(num){
                ans+=(num*(pow-1));
            }
            pow>>=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
