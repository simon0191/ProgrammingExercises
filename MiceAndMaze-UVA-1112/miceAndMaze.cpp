#include <cstdio>
#include <cstring>

int main(){
    bool first = true;
    int cases,cells,exit,time,cons,o,d,c,total,cont;
    int mat[105][105];
    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d %d %d",&cells,&exit,&time,&cons);
        memset(mat,-1,sizeof(mat));
        //printf("---> %d\n",cons);
        for(int g = 0;g<cons;++g){
            scanf("%d %d %d",&o,&d,&c);
            //printf("%d %d %d\n",o,d,c);
            mat[o-1][d-1] = c;
        }
        for(int k=0; k<cells; k++){
            for(int i=0; i<cells; i++){
                for(int j=0; j<cells; j++){
                    if(i!=k && j!=k && mat[i][k]!=-1 && mat[k][j]!=-1){
                        total = mat[i][k] + mat[k][j];
                        if(mat[i][j]==-1 || mat[i][j]>total){
                            mat[i][j]=total;
                        }
                    }
                }
            }
        }
        /*
        for(int i = 0;i<cells;++i){
            for(int j = 0;j<cells;++j){
                printf("%4d",mat[i][j]);
            }
            printf("\n");
        }
        */
        cont = 0;
        for(int i = 0;i<cells;++i){
            if(mat[i][exit-1]<=time && mat[i][exit-1] > -1){
                ++cont;
            }
        }
        if(first){
            first=false;
        }else{
            printf("\n");
        }
        printf("%d\n",cont+1);

    }
    return 0;
}

