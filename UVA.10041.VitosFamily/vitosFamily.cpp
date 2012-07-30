#include <cstdio>
#include <cstring>
#include <limits>
#include <algorithm>
#include <map>
#include <cmath>
#define ABS(X) ((X)<0?-(X):(X))

using namespace std;

int main(){
    int cases,n,aux,sum,ans;
    int left[30001],right[30001];
    scanf("%d",&cases);
    while(cases--){
        map<int,int> mapa;
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        sum = 0;
        ans = numeric_limits<int>::max();
        scanf("%d",&n);
        for(int i = 0;i<n;++i){
            scanf("%d",&aux);
            mapa[aux]++;
        }

        map<int,int>::iterator it = mapa.begin();
        map<int,int>::iterator it2 = mapa.begin();
        right[it->first] = n-(it->second);
        left[it->first] = 0;
        for(++it;it!=mapa.end();++it){
            sum+=(ABS(it->first-mapa.begin()->first)*it->second);
        }
        it2 = it = mapa.begin();
        ans = min(sum,ans);
        for(++it;it!=mapa.end();++it,++it2){
            left[it->first] = left[it2->first]+it2->second;
            right[it->first] = right[it2->first]-it->second;
            int dif = ABS(it->first-it2->first);
            sum = (sum - (dif*it->second)  + (dif*left[it->first]) -  (dif*(right[it->first])));
            ans = min(sum,ans);
        }

        printf("%d\n",ans);
    }
    return 0;
}


