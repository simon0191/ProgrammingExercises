#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int main(){
    int cases,files,dep,id,ndep,aux;
    bool mat[105][105];
    int deps[105];
    scanf("%d",&cases);
    while(cases--){
        memset(mat,false,sizeof(mat));
        memset(deps,0,sizeof(deps));
        scanf("%d%d",&files,&dep);
        for(int i = 0;i<dep;++i){
            scanf("%d%d",&id,&ndep);
            for(int i = 0;i<ndep;++i){
                scanf("%d",&aux);
                mat[id-1][aux-1] = true;
                deps[id-1]++;
            }
        }
        priority_queue<int,vector<int>,greater<int> > q;
        for(int i = 0;i<files;++i){
            if(deps[i]==0){
                q.push(i);
            }
        }
        bool first = true;
        while(!q.empty()){
            int act = q.top();
            q.pop();
            if(first){
                first = false;
            }else{
                printf(" ");
            }
            printf("%d",act+1);
            for(int i = 0;i<files;++i){
                if(mat[i][act]){
                    mat[i][act] = false;
                    deps[i]--;
                    if(deps[i]==0){
                        q.push(i);
                    }
                }
            }
        }
        printf("\n");
        if(cases){
            printf("\n");
        }

    }
    return 0;
}
