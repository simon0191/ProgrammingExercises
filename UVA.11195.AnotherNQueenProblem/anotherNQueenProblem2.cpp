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
typedef char Int;

Int n1;
int n;
int cont;
vector<vector<vector<Int> > >sols(15);
vector<Int> q;
short mat[15];
bool validate(vector<Int>& q2){
    for(int i = 0;i<n;++i){
        if(mat[q2[i]]&(1<<i))return false;
    }
    return true;
}
bool validate(){
    for(int i = 0;i<n;++i){
        if(mat[q[i]]&(1<<i))return false;
    }
    return true;
}
void countNqueens(short filUsed,int dL,int dR,char j){
    if(j == (n)){
        if(validate()){
            sols[n].push_back(q);
            cont++;
        }
        return;
    }
    for(char i = 0;i<n;++i){
        if(  (!(filUsed&  (1<<i)  )) && (!(dL&  (1<<(n1+j-i))  )) && (!(dR& (1<<(i+j)) )) ){
            q[j] = i;
            countNqueens(filUsed|(1<<i),  dL|(1<<(n1+j-i)) ,  dR|(1<<(i+j))  ,  j+1  );
        }
    }
}
int main(){
    int act;
    char line[20];
    int c =1;

    for(n = 3;n<15;++n){
        q.assign(n,0);
        countNqueens(0,0,0,0);
    }
	while(scanf("%d",&n) && n){
	    cont = 0;
	    n1 = n-1;
	    for(int i = 0;i<n;++i){
	        mat[i]=0;
	        scanf("%s",line);
            for(int j = 0;j<n;++j){
                if(line[j]=='*'){
                    mat[i]|=(1<<j);
                }
            }
	    }
	    for(int i = 0;i<sols[n].size();++i){
	        if(validate(sols[n][i]))cont++;
	    }
        printf("Case %d: %d\n",c++,cont);
	}
	return 0;
}




