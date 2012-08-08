
#include <cstdio>
#include <cstdlib>
#include <map>
#include <iostream>
#define UL unsigned long long
using namespace std;
int main(){
    char meses[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
    char dias[20][10] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    map<string,int> mapa;
    for(int i=0;i<19;++i){
        mapa[meses[i]] = i;
    }
    int d,a;
    char m[10];
    int casos;
    scanf("%d",&casos);
    printf("%d\n",casos);
    while(casos--){
        scanf("%d. %s %d",&d,m,&a);
        UL diass = 0;
        diass = (a*365)+(mapa[m]*20)+d;
//        printf("dias: %d\n",diass);
        int a_act = diass/260;
        int res = diass%260;
        int t = res%13;
        int v = res%20;
        printf("%d %s %d\n",t+1,dias[v],a_act);
    }
    return 0;
}

