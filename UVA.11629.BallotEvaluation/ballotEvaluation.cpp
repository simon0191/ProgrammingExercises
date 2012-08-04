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

void parse(char str[],vector<string>& strs){
    strs.clear();
  char * pch;
  pch = strtok (str," ");
  while (pch != NULL)
  {
    strs.push_back(pch);
    pch = strtok (NULL, " ");
  }
}
void debug(vector<string> strs){
    for(int i = 0;i<strs.size();++i){

    }
}
int main(){
    int p,g;
    char name[50];
    char line[10000];
    int n,n2;
    vector<string> strs;
    map<string,int> parties;
	scanf("%d %d",&p,&g);
	//cin>>p>>g;
	for(int i = 0;i<p;++i){
	    scanf("%s %d.%d",name,&n,&n2);
	    //printf("%s %lf\n",name,n);
	    parties[name] = ((n*10)+n2);
	}
	gets(line);
	for(int i = 1;i<=g;++i){
	    gets(line);
	    parse(line,strs);
	    int cont = 0;
	    //debug(strs);
	    for(int j = 0;j<strs.size()-1;j+=2){
	        cont+=parties[strs[j]];
	    }
	    bool ans;
	    if(strs[strs.size()-2] == "<"){
	        ans = (cont < (atoi(strs.rbegin()->c_str())*10));
	    }
	    else if(strs[strs.size()-2] == "<="){
            ans = (cont <= (atoi(strs.rbegin()->c_str())*10));
	    }
	    else if(strs[strs.size()-2] == ">"){
            ans = (cont > (atoi(strs.rbegin()->c_str())*10));
	    }
	    else if(strs[strs.size()-2] == ">="){
            ans = (cont >= (atoi(strs.rbegin()->c_str())*10));
	    }
	    else if(strs[strs.size()-2] == "="){
            ans = (cont == (atoi(strs.rbegin()->c_str())*10));
	    }
	    printf("Guess #%d was %s.\n",i,ans?"correct":"incorrect");
	}
	return 0;
}



