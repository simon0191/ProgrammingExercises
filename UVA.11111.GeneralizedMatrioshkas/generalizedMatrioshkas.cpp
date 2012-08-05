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

void toVec(string& line,vector<int>& v){
    v.clear();
    stringstream ss(line);
    int aux;
    while(ss>>aux){
        v.push_back(aux);
    }
}
bool gm(vector<int>& v){
    stack<int> nums;
    stack<int> sums;
    stack<int> act;
    for(int i = 0;i<v.size();++i){
        if(v[i] < 0){
            act.push(nums.empty()?-1:nums.top());
            if(!nums.empty() && nums.top() <= (-v[i])) return false;
            nums.push(-v[i]);
        }
        else{
            int s = 0;
            if(nums.empty() || (nums.top() != v[i]))return false;
            nums.pop();
            while(!act.empty() && (act.top() == v[i])){
                s+=sums.top();
                sums.pop();
                act.pop();
            }
            if(s >=  v[i])return false;
            sums.push(v[i]);
        }
    }
    return nums.empty();
    return true;
}
int main(){
	string line;
	vector<int> v;
	while(getline(cin,line) && line!=""){
	    toVec(line,v);
        puts((gm(v)?":-) Matrioshka!":":-( Try again."));
	}
	return 0;
}


