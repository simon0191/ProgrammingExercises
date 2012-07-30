#include <iostream>
#include <set>
#include <cstring>
#include <ctype.h>
#include <cstdio>
const int SIZE = 'z'-'a'+1;

using namespace std;
void mark(char mat[][1024],int x,int y,int marks[][1024],int cas){
    marks[x][y] = cas;
    char aux = mat[x][y];
    mat[x][y] = '*';
    if(isalpha(mat[x-1][y]) && mat[x-1][y] == aux){
        mark(mat,x-1,y,marks,cas);
    }
    if(isalpha(mat[x+1][y]) && mat[x+1][y] == aux){
        mark(mat,x+1,y,marks,cas);
    }
    if(isalpha(mat[x][y-1]) && mat[x][y-1] == aux){
        mark(mat,x,y-1,marks,cas);
    }
    if(isalpha(mat[x][y+1]) && mat[x][y+1] == aux){
        mark(mat,x,y+1,marks,cas);
    }
}
struct SS{
    char c;
    int cant;
    SS(char _c,int _cant):c(_c),cant(_cant){}
    bool operator<(const SS& ss)const{
        if(cant == ss.cant){
            return c<ss.c;
        }
        return cant>ss.cant;
    }
};
int main(){
    int cases,rows,cols;
    char mat[1024][1024];
    int marks[1024][1024];
    int arr[SIZE];
    memset(marks,0,sizeof(marks));

    scanf("%d",&cases);
    for(int c = 1;c<=cases;++c){
        memset(mat,'*',sizeof(mat));
        memset(arr,0,sizeof(arr));
        printf("World #%d\n",c);
        scanf("%d%d",&rows,&cols);
        for(int i = 1;i<=rows;++i){
            scanf("%s",mat[i]+1);
        }

        for(int i = 1;i<=rows;++i){
            for(int j =1;j<=cols;++j){
                if(marks[i][j] != c){
                    arr[mat[i][j]-'a']++;
                    mark(mat,i,j,marks,c);
                }
            }
        }
        set<SS> sete;
        for(int i = 0;i<SIZE;++i){
            if(arr[i]){
                sete.insert(SS(i+'a',arr[i]));
            }
        }
        set<SS>::iterator it;
        for(it = sete.begin();it!=sete.end();++it){
            printf("%c: %d\n",it->c,it->cant);
        }
    }
    return 0;
}
