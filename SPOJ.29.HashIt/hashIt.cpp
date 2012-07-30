#include <cstdio>
#include <cstring>

#define EQUALS(X,Y) (!strcmp((X),(Y)))
#define IS_EMPTY(X) (!(X)[0])

char mat[102][20];

int hash(char* buff){
    int resp = 0;
    for(int i = 1;*buff;++i,++buff){
        resp+=((*buff)*i);
    }
    resp*=19;
    return resp%101;
}
int find(char* buff,int _hash, int& posible){
    posible = -1;
    int pos = _hash;
    int pos2;
    if(EQUALS(buff,mat[pos])){
        return pos;
    }
    else if(mat[pos][0]==0){
        posible = pos;
    }
    for(int i = 1;i<20;++i){
        pos2 = (pos+(i*i)+(23*i))%101;
        if(EQUALS(buff,mat[pos2])){
            return pos2;
        }else if(posible == -1 && mat[pos2][0]==0){
            posible = pos2;
        }
    }
    return -1;
}

int main(){
    int cases,nInst,pos,pos2,cont,_hash,posible;
    char buff[25];
    bool found;

    for(scanf("%d",&cases);cases--;){
        //memset(mat,0,sizeof(mat));
        for(int i = 0;i<102;++i){
            mat[i][0] = 0;
        }
        cont = 0;
        for(scanf("%d",&nInst);nInst--;){
            scanf("%s",buff);
            _hash = hash(buff+4);
            pos = find(buff+4,_hash,posible);
            if(buff[0]=='A'){
                if(pos == -1 && posible!=-1){
                    strcpy(mat[posible],buff+4);
                    ++cont;
                }
            }
            else if(pos!= -1){
                    mat[pos][0] = 0;
                    --cont;
            }
        }
        printf("%d\n",cont);
        for(int i = 0;i<101;++i){
            if(mat[i][0]){
                printf("%d:%s\n",i,mat[i]);
            }
        }
    }
}
