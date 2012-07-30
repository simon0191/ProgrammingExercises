#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>

using namespace std;

void flood(int i,int j,int XX,int mat[][105]){
    mat[i][j] = -1;
    if(mat[i+1][j] == XX){
        flood(i+1,j,XX,mat);
    }
    if(mat[i-1][j] == XX){
        flood(i-1,j,XX,mat);
    }
    if(mat[i][j+1] == XX){
        flood(i,j+1,XX,mat);
    }
    if(mat[i][j-1] == XX){
        flood(i,j-1,XX,mat);
    }
}

int main(){
    int s,a,b;
    int mat[105][105];
    bool revised[105],wrong;
    string str;
    while(cin>>s && s){
        wrong = false;
        memset(mat,0,sizeof(mat));
        for(int i = 0;i<=s+1;++i){
            revised[i] = false;
            mat[0][i] = -1;
            mat[i][0] = -1;
            mat[i][s+1] = -1;
            mat[s+1][i] = -1;
        }
        cin.ignore();
        for(int i = 1;i<s;++i){
            int cont = 0;
            getline(cin,str);
            stringstream ss(str);
            while(ss>>a>>b && !(a==-1 || b==-1) && (cont < s)){
                mat[a][b] = i;
                a = b = -1;
                ++cont;
            }
            if(cont < s){
                wrong = true;
            }
        }
        if(!wrong){
            for(int i = 1;i<=s && !wrong;++i){
                for(int j = 1;j<=s && !wrong;++j){
                    if(mat[i][j] != -1){
                        if(!revised[mat[i][j]]){
                            revised[mat[i][j]] = true;
                            flood(i,j,mat[i][j],mat);
                        }
                        else{
                            wrong = true;
                            puts("wrong");
                        }
                    }
                }
            }
        }else{
            puts("wrong");
        }
        if(!wrong){
            puts("good");
        }
    }
    return 0;
}


