#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <iostream>

using namespace std;
const int AZ_SIZE = 'z'-'a'+1;

int main(){
    int cases,let,nLines;
    double ans,cost;
    unsigned char c;
    string line;
    cin>>cases;
    double v[2000];
    while(cases--){
        memset(v,0,sizeof(v));
        cin>>let;
        while(let--){
            cin>>c>>cost;
            v[c] = cost;
        }
        cin>>nLines;
        cin.ignore();
        ans = 0;
        while(nLines--){
            getline(cin,line);
            for(int i = 0;i<line.size();++i){
                ans+=v[line[i]];
            }
        }
        printf("%.2lf$\n",((ans)/100.0));
    }
}
