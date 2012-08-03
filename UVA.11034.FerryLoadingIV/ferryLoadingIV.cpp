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

int main(){
    int cases,l,cars,len,sum,cont;
    char side[15];
    char actS = 'l';
	scanf("%d",&cases);
	queue<int>* q;
	while(cases--){
	    queue<int> left;
	    queue<int> right;
        scanf("%d%d",&l,&cars);
        for(int i = 0;i<cars;++i){
            scanf("%d %s",&len,side);
            if(side[0] == 'l'){
                left.push(len);
            }
            else{
                right.push(len);
            }
        }

        l*=100;
        actS = 'l';
        q = &left;
        for(cont = 0;(!left.empty() || !right.empty());cont++){
            sum = 0;
            while(!q->empty()){
                if(sum+(q->front()) <= l){
                    sum+=q->front();
                    q->pop();
                }
                else{
                    break;
                }
            }
            if(actS == 'l'){
                actS = 'r';
                q = &right;
            }
            else{
                actS = 'l';
                q = &left;
            }
        }
        printf("%d\n",cont);
	}
	return 0;
}

