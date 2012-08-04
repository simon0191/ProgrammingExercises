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
    int cases;
	char s[50];
	map<string,int>::iterator it;
	scanf("%d",&cases);
	gets(s);
	gets(s);
	for(int i = 0;i<cases;++i){
	    if(i)puts("");
	    map<string,int> trs;
	    int cont = 0;
	    while(gets(s) && strcmp("",s)){
	        trs[s]++;
	        ++cont;
	    }
	    for(it = trs.begin();it != trs.end();++it){
	        double ans = (double(it->second)*100.0)/double(cont);
	        printf("%s %.4lf\n",(it->first).c_str(),ans);
	    }
	}
	return 0;
}



