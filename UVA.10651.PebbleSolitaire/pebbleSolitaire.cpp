#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;

void f(char s[],int& globalMin,int cont){
    bool mov = false;
    for(int i = 0;i<12;++i){
        if(s[i] == 'o'){
            //left
            if( i >= 2 && s[i-1]=='o' && s[i-2]=='-'){
                s[i] = s[i-1] = '-';
                s[i-2] = 'o';
                globalMin = min(globalMin,cont-1);
                f(s,globalMin,cont-1);
                s[i] = s[i-1] = 'o';
                s[i-2] = '-';
            }
            //right
            if( i <= 9 && s[i+1]=='o' && s[i+2]=='-'){
                s[i] = s[i+1] = '-';
                s[i+2] = 'o';
                globalMin = min(globalMin,cont-1);
                f(s,globalMin,cont-1);
                s[i] = s[i+1] = 'o';
                s[i+2] = '-';
            }
        }
    }
}
int ff(char s[],int pos,int cont){

}
int main(){
    int cases;
    scanf("%d",&cases);
    char s[20];
    while(cases--){
        scanf("%s",s);
        int minn = 0;
        for(int i = 0;s[i];++i){
            if(s[i]=='o')minn++;
        }
        f(s,minn,minn);
        printf("%d\n",minn);
    }
    return 0;
}
