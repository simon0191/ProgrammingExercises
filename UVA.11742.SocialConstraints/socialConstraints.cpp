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

struct Con{
    int a,b,con;
    Con(int _a,int _b,int _con):a(_a),b(_b),con(_con){}
    Con(){}
};

void calcDists(int sits[],int dist[][10],int n){
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            dist[ sits[i] ][ sits[j] ] = abs(i-j);
        }
    }
}
bool validateCons(int dist[][10],vector<Con>& cons){
    for(int i = 0;i<cons.size();++i){
        if(cons[i].con < 0){
            if(dist[ cons[i].a ][ cons[i].b ] < abs(cons[i].con)) return false;
        }
        else{
            if(dist[ cons[i].a ][ cons[i].b ] > abs(cons[i].con)) return false;
        }
    }
    return true;
}
int main(){
    int n,m,a,b,con;
    int fact[10];
    fact[0] = 1;
    for(int i = 1;i<10;++i){
        fact[i] = fact[i-1]*i;
    }

    int sits[10];
    int dist[10][10];

    while(scanf("%d %d",&n,&m)==2 && (n+m)){
        vector<Con> cons;
        for(int i = 0;i<m;++i){
            scanf("%d %d %d",&a,&b,&con);
            cons.push_back(Con(a,b,con));
        }
        for(int i = 0;i<n;++i){sits[i] = i;}
        int cont = fact[n];
        do{
            calcDists(sits,dist,n);
            if(!validateCons(dist,cons))--cont;
        }while(next_permutation(sits,sits+n));
        printf("%d\n",cont);
    }
    return 0;
}
