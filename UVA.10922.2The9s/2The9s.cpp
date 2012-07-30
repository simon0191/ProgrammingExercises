#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>

using namespace std;

int sum(char buff[]){
    int s = 0;
    for(int i = 0;buff[i];++i){
        s+=(buff[i]-'0');
    }
    return s;
}
int main(){
    char buff[1024];
    char buff2[1024];
    while(scanf("%s",buff)==1 && strcmp(buff,"0")){
        int s = sum(buff);
        if(s%9){
            printf("%s is not a multiple of 9.\n",buff);
        }else{
            int degree = 1;
            while(s != 9){
                sprintf(buff2,"%d",s);
                s = sum(buff2);
                ++degree;
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n",buff,degree);
        }

    }
    return 0;
}
