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
#include <stack>
#include <vector>


#define UL unsigned long long
#define LL long long
#define LD long double
#define EPS 1e-9

using namespace std;

int main(){
	char str[100010];
	bool ini,end;

	while(gets(str)){
	    list<char> s;
        list<char>::iterator it = s.begin();
        bool ini = false;
	    for(int i = 0;str[i];++i){
	        switch(str[i]){
	            case '[':
                    it = s.begin();
                    ini = true;
	            break;
	            case ']':
                    ini = false;
                    it = s.end();
	            break;
	            default:
	            if(ini){
                    s.insert(it,str[i]);
	            }
	            else{
                    s.push_back(str[i]);
	            }
	        }
	    }
	    copy(s.begin(), s.end(),
              std::ostream_iterator<char>(cout, ""));
        cout<<endl;
	}
	return 0;
}


