#include <cstdio>
#include <cstring>

int main(){
    char buff[1000000];
    int size;
    bool flag;
    while(scanf("%s",buff)==1 && buff[0]!='.'){
        flag = false;
        size = strlen(buff);
        for(int i = 1;i<size-1 && !flag;++i){
            if(size%i == 0){
                flag = true;
                for(int j = i;j<size && flag;j+=i){
                    if(strncmp(buff,buff+j,i)!=0){
                        flag = false;
                    }
                }
                if(flag){
                    printf("%d\n",size/i);
                }
            }
        }
        if(!flag)printf("1\n");
    }
    return 0;
}
