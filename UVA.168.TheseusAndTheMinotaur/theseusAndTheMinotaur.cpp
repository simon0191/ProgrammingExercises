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

const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;

void dfs(vector<vi>& graph,bool velas[],int mino,int tes,int kact,int k){
    if(!kact){
        velas[tes] = true;
        printf("%c ",'A'+tes);
        kact = k;
    }
    for(int i = 0;i<graph[mino].size();++i){
        if(graph[mino][i] != tes && !velas[graph[mino][i]]){
            dfs(graph,velas,graph[mino][i],mino,kact-1,k);
            return;
        }
    }
    printf("/%c\n",'A'+mino);
}

int main(){
	string line,line2,line3;
	char m,t;
	int k;
	bool velas[AZ_SIZE];
	while(cin>>line && line!="#"){
	    vector<vi> graph(AZ_SIZE);
	    memset(velas,false,sizeof velas);

	    line.erase(line.size()-1);//borrar punto
	    cin>>m>>t>>k;
	    stringstream ss(line);
	    while(getline(ss,line2,';')){
            for(int i = 2;i<line2.size();++i){
                graph[line2[0]-'A'].push_back(line2[i]-'A');
            }
	    }
	    dfs( graph,velas,m-'A',t-'A',k,k);
	}
	return 0;
}



