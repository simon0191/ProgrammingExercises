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

#define MEM(X,Y) memset(X,Y,sizeof(X))
#define MEM0(X) MEM(X,0)

const UL AZ_SIZE = 'Z'-'A'+1;

using namespace std;
#define iii pair<UL,ii>


UL dj(vector<vector<vi> >& graph,vector<UL>& time,int as,int dest){
    vector<vector<UL> > dist(graph.size(),vector<UL>(100,1000000000));
    dist[as][0] = 0;
    priority_queue< iii,vector<iii>,greater<iii> > pq;
    pq.push( iii(0,ii(0,as)) );
    while(!pq.empty()){
        iii front = pq.top();
        pq.pop();
        UL cost = front.first;
        int piso = front.second.first;
        UL a = front.second.second;
        if(cost==dist[a][piso]){
            for(UL j = 0;j<graph[a][piso].size();++j){
                int v = graph[a][piso][j];
                if( (dist[a][piso]+ (time[a]*abs(v-piso)) ) < dist[a][v] ){
                    dist[a][v] = dist[a][piso]+(time[a]*abs(v-piso));
                    pq.push( iii( dist[a][v]  ,ii(v,a)) );
                }
                for(int i = 0;i<graph.size();++i){
                    if(i!=a && !graph[i][piso].empty()){
                        if( (dist[a][piso]+60 ) < dist[i][piso] ){
                            dist[i][piso] = dist[a][piso]+60;
                            pq.push( iii( dist[i][piso],ii(piso,i)) );
                        }
                    }
                }
            }
        }
    }
    UL minn = 1000000000;
    for(int i = 0;i<graph.size();++i){
        minn = min(minn,dist[i][dest]);
    }
    return minn;
}

int main(){
	int n,d,act,ant;
	string str;

	while(scanf("%d %d",&n,&d)==2){

	    vector<UL> time(5);
	    vector<vector< vi > > graph(5,vector<vi>(100));
	    for(UL i = 0;i<n;++i){
	        scanf("%llu",&time[i]);
	    }
	    vector<UL> zeros;
	    cin.ignore();
        for(UL i = 0;i<n;++i){
            getline(cin,str);
            stringstream ss(str);
            ss>>ant;
            if(!ant){
                zeros.push_back(i);
            }
            while(ss>>act){
                graph[i][ant].push_back(act);
                graph[i][act].push_back(ant);
                ant = act;
            }
        }
        UL distmin = 1000000000;
        for(UL i = 0; i <zeros.size(); i++){
            distmin = min(distmin, dj(graph, time,zeros[i],d ));
        }
        if(distmin == 1000000000){
            puts("IMPOSSIBLE");
        }
        else{
            printf("%llu\n",distmin);
        }
	}
	return 0;
}



