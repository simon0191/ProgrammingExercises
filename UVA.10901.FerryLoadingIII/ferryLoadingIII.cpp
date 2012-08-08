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
#include <sstream>
#include <stack>
#include <vector>

#define UL unsigned long long
#define LL long long
#define LD long double
#define EPS 1e-9

const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;

struct SS{
    int time;
    int id;
    SS(int _t,int _id):time(_t),id(_id){}
};
int main(){
    int cases,n,t,m,time,cont;
    char side[15];
    char actS;
    bool first = true;
    queue<SS>* q;

    scanf("%d",&cases);
    vector<int> times;
    while(cases--){
        scanf("%d%d%d",&n,&t,&m);
        queue<SS> left,right;
        int id = 0;
        times.assign(m,0);
        for(int i = 0;i<m;++i){
            scanf("%d %s",&time,side);
            if(side[0] == 'l'){
                left.push(SS(time,id++));
            }
            else{
                right.push(SS(time,id++));
            }
        }

        /*
        2 10 3
        10 right
        25 left
        40 left
        */
        actS = 'l' ;
        cont = 0;
        q = &left;
        for(;(!left.empty() || !right.empty());cont+=t){
            if( (left.empty() || (left.front().time > cont)) && (right.empty() || (right.front().time > cont)) ){
                cont =  min(left.empty()?right.front().time:left.front().time,
                            right.empty()?left.front().time:right.front().time);
            }
            int cap = 0;
            while(!( q->empty() || (q->front().time > cont) || (cap >= n) )){
                times[q->front().id] = cont+t;
                q->pop();
                //printf("%d\n",);
                ++cap;
            }
            if(actS == 'l'){
                q = &right;
                actS = 'r';
            }
            else{
                q = &left;
                actS = 'l';
            }
        }
        if(!first)puts("");
        else first = false;
        for(int i = 0;i<times.size();++i){
            printf("%d\n",times[i]);
        }
    }
	return 0;
}



