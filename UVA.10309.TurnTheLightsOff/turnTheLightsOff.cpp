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

void _switch(vector<int>& mat,int x, int y){
    mat[x]^= (1<<y);
    if(x-1 >=0)mat[x-1]^=(1<<y);
    if(y-1 >=0)mat[x]^=(1<<(y-1));
    if(x+1 <10)mat[x+1]^=(1<<(y));
    if(y+1 <10)mat[x]^=(1<<(y+1));
}
bool verify(vector<int>& mat){
    for(int i = 0;i<10;++i){
        if(mat[i])return false;
    }
    return true;
}
bool f(vector<int> mat,int mask,int &cont){
    cont = 0;
    for(int i = 0;i<10;++i){
        if(mask&(1<<i)){
            _switch(mat,0,i);
            ++cont;
        }
    }
    for(int i = 1;i<10;++i){
        for(int j = 0;j<10;++j){
            if( mat[i-1]&(1<<j) ){
                _switch(mat,i,j);
                ++cont;
            }
        }
    }
    return verify(mat);
}
int main(){
	char name[1024],buff[16];
	int cont;
	vector<int> mat;
	while(scanf("%s",name)==1 && strcmp(name,"end")){
	    mat.assign(10,0);
        for(int i = 0;i<10;++i){
            scanf("%s",buff);
            for(int j = 0;buff[j];++j){
                if(buff[j]=='O')mat[i]|=(1<<j);
            }
        }
        int len = (1<<10);
        int minn = 100;
        int cont;
        for(int i = 0;i<len;++i){
            cont = 0;
            if(f(mat,i,cont)){
                minn = min(minn,cont);
            }
        }
        if(minn > 100)minn = -1;
        printf("%s %d\n",name,minn);
	}
	return 0;
}



