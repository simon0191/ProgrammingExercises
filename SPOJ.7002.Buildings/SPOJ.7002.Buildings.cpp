#include <cstdio>
#include <cstring>
#define LL unsigned long long

LL ans[100050];
int builds[100050];
int fins[100050];

LL f(LL nBuilds,LL pos){
    return (pos+1)*(nBuilds-pos);
}
void rec(int ini, int fin,int iniFins){
    if(builds[ini] == 0 || ini==fin)return;

    int n = fin-ini,lower = builds[ini],cont = 0;
    for(int i = ini;i<fin;++i){
        if(builds[i]<lower){
            lower = builds[i];
        }
    }
    for(int i = 0;i<n;++i){
        ans[i+ini]+=f(n,i)*lower;
        builds[i+ini]-=lower;
        if(builds[i+ini]==0){
            fins[cont+iniFins] = i+ini;
            ++cont;
        }
    }
    fins[cont+iniFins] = fin;
    ++cont;
    for(int i =0;i<cont;++i){
        rec(ini,fins[i+iniFins],iniFins+cont);
        ini = fins[i+iniFins]+1;
    }
}
int main(){
    int nBuilds;
    scanf("%d",&nBuilds);
    for(int i = 0;i<nBuilds;++i){
        scanf("%d",builds+i);
        ans[i] = 0;
    }
    rec(0,nBuilds,0);
    for(int i = 0;i<nBuilds;++i){
        if(i)printf(" ");
        printf("%llu",ans[i]);
    }
    puts("");
    return 0;
}

