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

const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;

struct SS{
    int id;
    int time;
    SS(){}
    SS(int _id,int _time):id(_id),time(_time){}
    bool operator<(const SS& ss)const{
        if(time < ss.time)return true;
        if(time > ss.time)return false;
        return (id < ss.id);
    }
    bool operator>(const SS& ss)const{
        if(time > ss.time)return true;
        if(time < ss.time)return false;
        return (id > ss.id);
    }
};
int main(){
    char s[20];
    int n,id,per;
    set<SS> sete;
	while(scanf("%s",s)==1 && strcmp("#",s)){
	    scanf("%d %d",&id,&per);
        sete.insert(SS(id,per));
	}
	scanf("%d",&n);
	priority_queue<SS,vector<SS>,greater<SS> > q;
	set<SS>::iterator it = sete.begin();
	int cont = 1;
	int n2 = n*sete.size()+1;
	map<int,int> mapa;
	for(int i = 0;i<n2;++i){
	    cont = ++mapa[it->id];
	    q.push(SS(it->id,it->time*cont));
        //printf("%d\n",it->id);
        ++it;
        if(it == sete.end()){
            it = sete.begin();
        }
	}
	while(n--){
	    printf("%d\n",q.top().id);
	    q.pop();
	}
	return 0;
}



