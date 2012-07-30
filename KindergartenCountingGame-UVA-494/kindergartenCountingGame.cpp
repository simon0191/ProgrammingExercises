#include <cstdio>
#include <cstring>
#include <cctype>
int main(){
    char buff[100000],*str;
    int cont,i;
    bool alpha;
    while(gets(buff)){
        alpha = false;
        cont = 0;
        for(i = 0;buff[i];++i){
            if(isalpha(buff[i])){
                alpha = true;
            }else if(alpha){
                cont++;
                alpha = false;
            }
        }
        if(isalpha(buff[i-1]))cont++;
        printf("%d\n",cont);
    }
    return 0;
}

