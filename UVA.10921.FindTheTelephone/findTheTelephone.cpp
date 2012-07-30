#include <cstdio>
#include <sstream>

using namespace std;
char f(char c){
    switch(c){
        case 'A':case'B':case 'C':return '2';
        case 'D':case 'E':case 'F':return '3';
        case 'G':case 'H':case 'I':return '4';
        case 'J':case 'K':case 'L':return '5';
        case 'M':case 'N':case 'O':return '6';
        case 'P':case 'Q':case 'R':case 'S':return '7';
        case 'T':case 'U':case 'V':return '8';
        case 'W':case 'X':case 'Y':case 'Z':return '9';
    }
}
int main(){
    char buff[1024];
    while(scanf("%s",buff) == 1){
        for(int i = 0;buff[i];++i){
            if(!(buff[i] == '-' || buff[i] == '0' || buff[i] == '1')){
                buff[i] = f(buff[i]);
            }
        }
        printf("%s\n",buff);
    }
    return 0;
}

