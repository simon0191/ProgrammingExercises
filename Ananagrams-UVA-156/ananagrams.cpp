#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
string toUpper(string& str){
    string resp = str;
    for(int i = 0;i<str.size();++i){
        resp[i] = toupper(resp[i]);
    }
    return resp;
}
int main(){
    string str,str2;
    map<string,string> mapa;
    pair< map<string,string>::iterator,bool> p;
    map<string,string>::iterator it;
    while(cin>>str && str[0]!='#'){
        str2 = toUpper(str);
        sort(str2.begin(),str2.end());
        if( (p = mapa.insert(pair<string,string>(str2,str))).second == false){//exists
            p.first->second = "";
        }
    }
    set<string> s;
    for(it = mapa.begin();it!=mapa.end();++it){
        if(it->second != ""){
            s.insert(it->second);
        }
    }
    set<string>::iterator it2;
    for(it2 = s.begin();it2!=s.end();++it2){
        cout<<(*it2)<<endl;
    }
    return 0;
}
