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

const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;

int main(){
    int cases;
    char buff[5];
    char ans[100];
    char* a = ans;
	scanf("%d",&cases);
	gets(buff);
	gets(buff);
	stack<char> ops;
	bool first = true;
	while(gets(buff)){
	    bool next = false;
	    switch(buff[0]){
	        case '(':
                ops.push(buff[0]);
            break;
            case ')':
                while(ops.top() != '('){
                    sprintf(a,"%c",ops.top());
                    a++;
                    ops.pop();
                }
                ops.pop();
            break;
            case '+':case '-':
                while(!ops.empty() && (ops.top()!='(')){
                    sprintf(a,"%c",ops.top());
                    a++;
                    ops.pop();
                }
                ops.push(buff[0]);
            break;
            case '*':case '/':
                while(!(ops.empty() || (ops.top() == '+') || (ops.top() == '-') || (ops.top()=='('))){
                      sprintf(a,"%c",ops.top());
                      a++;
                      ops.pop();
                }
                ops.push(buff[0]);
            break;
            default:
                if(strcmp(buff,"")){
                    sprintf(a,"%c",buff[0]);
                    a++;
                }
                else{
                    next = true;
                }
	    }
	    if(next){
	        if(!first){
                puts("");
            }
            else{
                first = false;
            }
	        while(!ops.empty()){
	            sprintf(a,"%c",ops.top());
	            a++;
	            ops.pop();
	        }
	        //puts("\n");
	        printf("%s\n",ans);
	        a = ans;
	        ops = stack<char>();
	    }
	}
	if(!first){
        puts("");
    }
    else{
        first = false;
    }
    while(!ops.empty()){
        sprintf(a,"%c",ops.top());
        a++;
        ops.pop();
    }
    //puts("\n");
    printf("%s\n",ans);
    a = ans;
    ops = stack<char>();
	return 0;
}


