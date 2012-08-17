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
#define LEAK -1
#define GAS -2
#define MECH -3
#define GOAL -4

bool validate(int events[],int dists[],int size,double _cap){
    int leaks = 0;
    double dist,cap = _cap;
    double fuelCons = events[0];
    for(int i = 1;i<size;++i){
        dist = (dists[i]-dists[i-1]);
        cap -= (leaks*dist);
        cap -= ((fuelCons/100.0)*dist);
        if(cap<0.0)return false;
        switch(events[i]){
            case LEAK:
                leaks++;
            break;
            case GAS:
                cap = _cap;
            break;
            case MECH:
                leaks = 0;
            break;
            case GOAL:
                return (cap>=0.0);
            break;
            default:
                fuelCons = events[i];
            break;
        }
    }
    return false;
}

double bs(int events[],int dists[],int size,double l,double r){
    if(abs(r-l)<EPS) return l;
    double mid = (l+r)/2.0;
    if(validate(events,dists,size,mid)){
        return bs(events,dists,size,l,mid);
    }
    return bs(events,dists,size,mid,r);
}
int main(){
    int d,fuel;
    char line[32];
    int dists[60];
    int events[60];
    int size = 0;
	while(scanf("%d",&d)==1 && gets(line) && strcmp(" Fuel consumption 0",line)){
	    size = 0;
	    fuel = atoi(line+18);
	    dists[size] = 0;
	    events[size++] = fuel;
        while(scanf("%d %s",&d,line)==2 && strcmp(line,"Goal")){
            switch(line[2]){
                case 'e'://Fuel
                    scanf("%s %d",line,&fuel);
                    dists[size] = d;
                    events[size++] = fuel;
                break;
                case 'a'://Leak
                    dists[size] = d;
                    events[size++] = LEAK;
                break;
                case 's'://Gas
                    scanf("%s",line);
                    dists[size] = d;
                    events[size++] = GAS;
                break;
                case 'c'://Mechanic
                    dists[size] = d;
                    events[size++] = MECH;
                break;

            }
        }
        dists[size] = d;
        events[size++] = GOAL;
        /*
        puts("-------------");
        for(int i = 0;i<size;++i){
            printf("(%d: %d),",dists[i],events[i]);
        }
        puts("\n-------------");
        */
        printf("%.3lf\n",bs(events,dists,size,0.0,10000.0));
	}
	return 0;
}



