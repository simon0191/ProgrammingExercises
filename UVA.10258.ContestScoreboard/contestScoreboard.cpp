#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>


#define UL unsigned long long
#define LL long long
#define LD long double
#define EPS 1e-9

using namespace std;

struct SS{
    int id;
    int acumTime;
    set<int> sete;
    SS(){
        id = numeric_limits<int>::max();
        acumTime = 0;
    }
};
bool ff(const SS& s1,const SS&s2){
    if(s1.sete.size() > s2.sete.size())return true;
    if(s1.sete.size() < s2.sete.size())return false;
    if(s1.acumTime > s2.acumTime)return true;
    if(s1.acumTime < s2.acumTime)return false;
    return s1.id < s2.id;
}
int main() {

    int cases,contestant,problem,time;
    char veredict[3];
    char buff[200];
    int problems[110][10];
    scanf("%d",&cases);
    gets(buff);
    gets(buff);
    for(int c = 0;c<cases;++c){
        memset(problems,0,sizeof(problems));
        vector< SS > v(110);
        if(c)puts("");
        while(gets(buff) && buff[0]){
            sscanf(buff,"%d %d %d %c",&contestant,&problem,&time,veredict);
            v[contestant].id = contestant;
            switch(veredict[0]){
                case 'C':
                    if(v[contestant].sete.insert(problem).second){
                        //problems[contestant][problem]+=time;
                        v[contestant].acumTime += (problems[contestant][problem]+time);
                    }
                break;
                case 'I':
                    if(v[contestant].sete.find(problem) == v[contestant].sete.end()){
                        problems[contestant][problem]+=20;
                    }
                break;
            }
        }
        sort(v.begin(),v.end(),ff);

        for(int i = 0;i<v.size();++i){
            if(v[i].id < numeric_limits<int>::max()){
                printf("%d %d %d\n",v[i].id,(int)v[i].sete.size(),v[i].acumTime);
            }
        }
    }
    return 0;
}
