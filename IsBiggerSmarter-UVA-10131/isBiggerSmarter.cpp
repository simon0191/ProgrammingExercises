#include <cstdio>
#include <vector>
#include <set>

using namespace std;

struct EE{
    int w,id,s;
    EE(){}
    bool operator<(const EE& e)const{
        if(w==e.w)return s>e.s;
        return w<e.w;
    }
};
int main(){
    EE e;
    set<EE> sete;
    int i = 1,max_lis,index;
    while(scanf("%d %d",&e.w,&e.s)==2){
        e.id = i++;
        sete.insert(e);
    }
    vector<EE> a(sete.begin(),sete.end());
    vector<int> lis(a.size(),1);
    vector<int> path(a.size(),-1);

    max_lis = 1;
    index = 0;
    for(int i = a.size()-2;i>=0;--i){
        for(int j = i+1;j<a.size();++j){
            if(a[i].s > a[j].s && a[i].w < a[j].w){
                if(lis[i] < lis[j]+1){
                    lis[i] = lis[j]+1;
                    path[i] = j;
                }
                if(max_lis < lis[i]){
                    max_lis = lis[i];
                    index = i;
                }
            }
        }
    }
    printf("%d\n",max_lis);
    while(index != -1){
        printf("%d\n",a[index].id);
        index = path[index];
    }
    return 0;
}
