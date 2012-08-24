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

#define INV 2
#define FALSE 0
#define TRUE 1

#define UP_TO_DATE -1

using namespace std;


vector<bool> v(1024100,0);
int card[1022];
int sizes[1022];
char ops[1022];

int operate(int left,int right){
    switch(right){
        case TRUE:return TRUE;
        case FALSE:return FALSE;
    }
    switch(left){
        case TRUE:return FALSE;
        case FALSE:return TRUE;
        case INV: return UP_TO_DATE;
        case UP_TO_DATE:return INV;
    }
}
int applyTransf(int updateType,int a, int lim){
    int cont = 0;
    for(int i = a;i<lim;++i){
        switch(updateType){
            case INV:v[i] = (!v[i]);break;
            case TRUE:v[i] = true;break;
            case FALSE:v[i] = false;break;
        }
        if(v[i])++cont;
    }
    return cont;
}

void bulkUpdate(int updateType,int a,int b,int size,int sq){
    int lim,cont;
    int upX = a/sq;
    int doX = b/sq;

    // aplicar la transformacion anterior [limInferior,a)
    cont = applyTransf(ops[upX],upX*sq,a);
    lim = min((upX+1)*sq,size);
    // aplicar la transformacion actual (teniendo encuenta la anterior)
    // [a,min(lim,b+1))
    cont += applyTransf(operate(ops[upX],updateType),a, min(lim,b+1));
    if(upX==doX){
        cont+=applyTransf(ops[upX],b+1,lim);
        card[upX] = cont;
    }
    else{
        card[upX] = cont;

        cont = applyTransf(operate(ops[doX],updateType),doX*sq,min(b+1,size));
        lim = min((doX+1)*sq,size);
        cont+=applyTransf(ops[doX],b+1,lim);
        card[doX] = cont;
    }
    for(int i = upX+1;i<doX;++i){
        ops[i] = operate(ops[i],updateType);
    }
    ops[upX] = ops[doX] = UP_TO_DATE;
}
int contOnes(int a, int lim,int opType){
    int cont = 0;
    for(int i = a;i<lim;++i){
        switch(opType){
            case INV:cont+=(v[i]?0:1);break;
            case TRUE:++cont;break;
            case UP_TO_DATE:cont+=(v[i]?1:0);break;
        }
    }
    return cont;
}
int rsq(int a,int b,int size,int sq){
    int upX = a/sq;
    int doX = b/sq;
    int lim = (upX+1)*sq;
    int cont = contOnes(a,min(lim,b+1),ops[upX]);
    if(upX != doX){
        for(int i = upX+1;i<doX;++i){
            switch(ops[i]){
                case INV:
                    cont+= (sizes[i]-card[i]);
                break;
                case TRUE:
                    cont+=(sizes[i]);
                break;
                case UP_TO_DATE:
                    cont+=(card[i]);
                break;
            }
        }
        cont += contOnes((doX*sq),min(b+1,size),ops[doX]);
    }
    return cont;
}

void init(int sq,int size){
    int ss = sq*sq,cont,ii=0;
    for(int i = 0;i<sq;++i){
        cont = 0;
        for(int j = 0;j<sq;++j){if(v[ii++])++cont;}
        card[i] = cont;
        sizes[i] = sq;
    }
    if(ss < size){
        sizes[sq] = (size-ss);
        cont = 0;
        for(int i = ss;i< size;++i){if(v[ii++])++cont;}
        card[sq] = cont;

    }
    memset(ops,UP_TO_DATE,sizeof(ops[0])*(sq+5));
}
void debug(vector<bool>& v,int size){
    return;
    int sq = floor(sqrt(size));
    puts("---------------------");
    for(int i = 0;i<size;++i){
        if(!(i%sq))printf("|");
        printf("%c",v[i]?'1':'0');
    }
    printf("\n|");
    for(int i =0;i<sq+1;++i){
        printf("%4d|",ops[i]);
    }
    printf("\n|");
    for(int i =0;i<sq+1;++i){
        printf("%4d|",card[i]);
    }
    puts("\n---------------------");
}
int main(){
    int cases,n,rep,q,a,b;
    char buff[64];
    scanf("%d",&cases);

    for(int c = 1;c<=cases;++c){
        printf("Case %d:\n",c);
        scanf("%d",&n);
        int cont = 0;
        for(int i = 0 ;i<n;++i){
            scanf("%d %s",&rep,buff);
            for(int j = 0;j<rep;++j){
                for(int k = 0;buff[k];++k){
                    v[cont++] = ((buff[k]=='1')?1:0);
                }
            }
        }
        int sq = floor(sqrt(cont));
        init(sq,cont);

        int qs = 1;
        scanf("%d",&q);
        debug(v,cont);
        for(int i = 1;i<=q;++i){
            scanf("%s %d %d",buff,&a,&b);
            switch(buff[0]){
                case 'F':
                    bulkUpdate(TRUE,a,b,cont,sq);
                break;
                case 'E':
                    bulkUpdate(FALSE,a,b,cont,sq);

                break;
                case 'I':
                    bulkUpdate(INV,a,b,cont,sq);
                break;
                case 'S':
                    printf("Q%d: %d\n",qs++,rsq(a,b,cont,sq));
                break;
            }
            debug(v,cont);
        }
    }
	return 0;
}



