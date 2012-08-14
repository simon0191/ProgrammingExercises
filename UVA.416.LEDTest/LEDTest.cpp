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

int toNum(const char* s){
    int n = 0;
    for(int i = 0;s[i];++i){
        n<<=1;
        if(s[i]=='Y')n|=1;
    }
    return n;
}
bool match(int a,int b,int & burned){
    for(int i = 0;i<7;++i){
        if( (a&(1<<i)) && (burned&(1<<i)) ) return false;
        if( (a&(1<<i)) && (!(b&1<<i)))return false;
        if( (b&(1<<i)) && (!(a&1<<i))){
            burned|=(1<<i);
        }
    }
    return true;
}
bool bt(const vector<int>& seq,const vector<int>& nums,int pos,int toMatch,int burned){
    if((toMatch < 0) || !match(seq[pos],nums[toMatch],burned))return false;
    if(pos == (seq.size()-1))return true;
    return bt(seq,nums,pos+1,toMatch-1,burned);
}
int main(){
	int n;
	vector<int> nums;
	nums.push_back(toNum("YYYYYYN"));
    nums.push_back(toNum("NYYNNNN"));
    nums.push_back(toNum("YYNYYNY"));
    nums.push_back(toNum("YYYYNNY"));
    nums.push_back(toNum("NYYNNYY"));
    nums.push_back(toNum("YNYYNYY"));
    nums.push_back(toNum("YNYYYYY"));
    nums.push_back(toNum("YYYNNNN"));
    nums.push_back(toNum("YYYYYYY"));
    nums.push_back(toNum("YYYYNYY"));
    bool first = true;
	char s[16];
	while(scanf("%d",&n) == 1 && n){
	    vector<int> seq;
	    for(int i = 0;i<n;++i){
	        scanf("%s",s);
	        seq.push_back(toNum(s));
	    }
	    bool mismatch = true;
        for(int i = 9;i>=0 && mismatch;--i){
            if (bt(seq,nums,0,i,0)) mismatch = false;
        }
	    printf("%s\n",(mismatch?"MISMATCH":"MATCH"));
	}
	return 0;
}



