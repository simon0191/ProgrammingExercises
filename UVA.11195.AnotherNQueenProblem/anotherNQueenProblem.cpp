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
Int q[15];
short mat[15];
bool validate(){
    for(int i = 0;i<n;++i){
        if(mat[q[i]]&(1<<i))return false;
           //mat[q[i]][i])return false;
    }
    return true;
}
/*
void countNqueens(short filUsed,int dL,int dR,char j){
    if(j == (n)){
        if(validate())cont++;
        return;
    }
    short _filUsed = 1;
    for(int i = 0;i<n;++i){
        int _dL = 1<<(n1+j-i);
        int _dR = 1<<(i+j);
        if(  (!(filUsed&  _filUsed  )) && (!(dL&_dL)) && (!(dR&_dR)) ){
            q[j] = i;
            countNqueens(filUsed|_filUsed,  dL|_dL ,  dR|_dR  ,  j+1  );
        }
        _filUsed<<=1;
    }
}*/

void countNqueens(short filUsed,int dL,int dR,char j){
    if(j == (n)){
        if(validate())cont++;
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
    vector<vector<Int> > sols;
	while(scanf("%d",&n) && n){
	    getchar();
	    cont = 0;
	    n1 = n-1;
	    for(int i = 0;i<n;++i){
	        mat[i]=0;
	        //scanf("%s",line);
            for(int j = 0;j<n;++j){
                if(getchar() == '*'){
                //if(line[j]=='*'){
                    mat[i]|=(1<<j);
                }
            }
            getchar();
	    }
        countNqueens(0,0,0,0);
        printf("Case %d: %d\n",c++,cont);
	}
	return 0;
}



