#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<set>
#include <cctype>
using namespace std;

int main(){
    int cases,a,b,t,lim,aux;
    scanf("%d",&cases);
    for(int c = 1;c<=cases;++c){
        printf("Case #%d:",c);
        scanf("%d %d",&a,&b);
        if(a==b){
            printf(" 0");
        }
        else{
            t = a-b;
            if(t >= b && t >0){
                lim = sqrt(t)+1;
                set<int> div;
                for(int i = 1;i<=lim;++i){
                    if((t%i) == 0){
                        if(i > b){
                            div.insert(i);
                        }
                        aux = t/i;
                        if(aux > b){
                            div.insert(aux);
                        }
                    }
                }
                set<int>::iterator it;
                for(it = div.begin();it!=div.end();++it){
                    printf(" %d",(*it));
                }
            }
        }
        puts("");
    }
    return 0;
}
