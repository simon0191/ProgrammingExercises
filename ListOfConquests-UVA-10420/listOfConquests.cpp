#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define UL unsigned long long

using namespace std;
int main(){
    int nLines;
    string str;
    map<string,int> mapa;
    map<string,int>::iterator it;
    cin>>nLines;
    while(nLines--){
        cin>>str;
        mapa[str]++;
        getline(cin,str);
    }
    for(it = mapa.begin();it!=mapa.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}

