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

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;
//          N  L  S  O
int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0,-1};

int main(){
    map<char,int> mapa;
    mapa['N'] = 0;
    mapa['L'] = 1;
    mapa['S'] = 2;
    mapa['O'] = 3;

    int fils,cols,size;
    char mat[128][128];
    char buff[50010];
    while(scanf("%d %d %d",&fils,&cols,&size)==3 && (fils+cols+size)){
        int xi,yi;
        for(int i = 0;i<fils;++i){
            scanf("%s",mat[i]);
            for(int j = 0;mat[i][j];++j){
                if(isalpha(mat[i][j])){
                    xi = i;
                    yi = j;
                }
            }
        }
        int dir = mapa[mat[xi][yi]];
        int cont = 0;
        scanf("%s",buff);
        for(int i = 0;buff[i];++i){
            switch(buff[i]){
                case 'D':
                    dir = (dir+1)%4;
                break;
                case 'E':
                    dir = (dir+3)%4;
                break;
                case 'F':
                    if((dx[dir]+xi < fils) && (dx[dir]+xi >= 0) && (dy[dir]+yi<cols) && (dy[dir]+yi >= 0)){
                        if( mat[ dx[dir]+xi ][ dy[dir]+yi ] != '#' ){
                            xi+=dx[dir];
                            yi+=dy[dir];
                        }
                        if(mat[xi][yi]=='*'){
                            ++cont;
                            mat[xi][yi] = '.';
                        }
                    }
                break;
            }
        }
        printf("%d\n",cont);
    }
	return 0;
}


