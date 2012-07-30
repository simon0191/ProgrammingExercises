#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <climits>
#include <queue>

using namespace std;

struct Arc{
    int id,cost;
    Arc(int _id, int _cost):id(_id),cost(_cost){}

    bool operator > (const Arc &arc) const{
        if(cost == arc.cost){
            return id < arc.id;
        }
        return cost > arc.cost;
    }
};

using namespace std;

int dijkstra2(vector< vector < Arc > > &graph, int s, int e,vector<Arc>& dist)
{
    dist[s] = Arc(-1,0);
    priority_queue<Arc, vector<Arc>, greater<Arc> > q;
    q.push( Arc(s, 0) );
    while(!q.empty())
    {
        Arc tmp = q.top();
        q.pop();
        int u = tmp.id;
        //if(u==e) break;
        for(int i = graph[u].size()-1; i>=0 ;--i)
        {
            int v = graph[u][i].id, cost = graph[u][i].cost;
            if(dist[u].cost + cost <= dist[v].cost)
            {
                dist[v].id = u;
                dist[v].cost = dist[u].cost + cost;
                q.push(Arc(v, dist[v].cost));
            }
        }
    }
    return dist[e].cost;
}

int main(){
    int n,m,pos,pos2,aux,resp;
    int mat[15][105];
    while(scanf("%d%d",&n,&m)==2){
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                scanf("%d",mat[i]+j);
            }
        }
        /*for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                printf("%2d ",mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */
        vector<vector<Arc> > graph(n*m+2);
        for(int i=0;i<n;++i){
            graph[0].push_back(Arc(i+1,mat[i][0]));
        }
        for(int i = 0;i<n;++i){
            for(int j=0;j<m-1;++j){
                for(int k = -1;k<=1 && (i+k)<n;++k){
                    if(i+k < 0){
                        pos = ((j*n)+i)+1;
                        pos2 = (((j+1)*n)+(n-1))+1;
                        graph[pos].push_back(Arc(pos2,mat[n-1][j+1]));
                    }else{
                        pos = ((j*n)+i)+1;
                        pos2 = (((j+1)*n)+(i+k))+1;
                        graph[pos].push_back(Arc(pos2,mat[i+k][j+1]));
                    }
                }
            }
        }
        for(int i=0;i<n;++i){
            pos = (((m-1)*n)+i)+1;
            pos2 = n*m+1;
            graph[pos].push_back(Arc(pos2,0));
        }
        /*
        for(int i = 0;i<graph.size();++i){
            printf("%d: ",i);
            for(int j = 0;j<graph[i].size();++j){
                printf("(%d,%d),",graph[i][j].id,graph[i][j].cost);
            }
            printf("\n");
        }
        printf("\n");
        */
        vector<Arc> dist(graph.size(),Arc(-1,INT_MAX));
        //printf("%d\n",dijkstra(graph,0,m*n+1));
        resp = dijkstra2(graph,0,m*n+1,dist);
        stack<int> pila;
        aux = dist[n*m+1].id;
        while(dist[aux].id != -1){
            pila.push((aux-1)%n);
          //  printf("%2d ",aux);
            aux = dist[aux].id;
        }
        while(!pila.empty()){
            printf("%d ",pila.top()+1);
            pila.pop();
        }
        printf("\n");
        printf("%d\n",resp);
    }
    return 0;
}
