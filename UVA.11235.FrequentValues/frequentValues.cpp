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

struct Tree{
    int freq,l,r;
    Tree *left,*right;
    Tree(){left = right = NULL;}
    Tree(int _freq,int _l,int _r,Tree* _left,Tree* _right):
        freq(_freq),l(_l),r(_r),left(_left),right(_right){}
    bool isLeaf(){
        return ((left == NULL) && (right == NULL));
    }
};
void initTree(vector<pair<int,pair<int,int> > >& freq,int l,int r,Tree* & t){
    if(l == r){
        int fre = ((freq[l].second.second)-(freq[l].second.first)+1);
        t = new Tree(fre,
                     freq[l].second.first,
                     freq[l].second.second,
                     NULL,NULL);
        //printf("---->  %d %d %d\n",fre,t->l,t->r);
        return;
    }
    t = new Tree();
    t->l = freq[l].second.first;
    t->r = freq[r].second.second;
    int mid = (r+l)/2;
    initTree(freq,l,mid,t->left);
    initTree(freq,mid+1,r,t->right);
    t->freq = max(t->left->freq,t->right->freq);
}
int findMaxFreq(Tree* t,int l,int r){
    //printf("***** Entre con L:%d y R:%d\n",l,r);
    if((t->l == l) && (t->r==r))return t->freq;
    if(t->isLeaf()){
        //printf("[L:%d,R:%d]\n",l,r);
        return (r-l+1);//((r-l)+1);
    }
    //if((t->l <= l) && (t->r>=r))
    int maxL = 0,maxR = 0;
    //printf("********* Left tree: %d %d\n",t->left->l,t->left->r);
    //printf("********* Right tree: %d %d\n",t->right->l,t->right->r);
    if((t->left->r >= l))maxL = findMaxFreq(t->left,l,min(t->left->r,r));
    if((t->right->l <= r))maxR = findMaxFreq(t->right,max(t->right->l,l),r);
    return max(maxL,maxR);
}
void debug(map<int,pair<int,int> >& mapa){
    map<int,pair<int,int> >::iterator it;
    puts("--------------------");
    for(it = mapa.begin();it!=mapa.end();++it){
        printf("->%d:(%d,%d)\n",it->first,(it->second).first,(it->second).second);
    }
    puts("--------------------");
}
int main(){
	int n,q,aux,l,r;
	while(scanf("%d",&n)==1 && n){
	    map<int,pair<int,int> > mapa;
	    scanf("%d",&q);
	    for(int i = 1;i<=n;++i){
	        scanf("%d",&aux);
	        pair<int,int>& al = mapa[aux];
	        if(!al.first)al.first = i;
	        al.second = i;
	    }
	    //debug(mapa);
	    vector<pair<int,pair<int,int> > > freq(mapa.begin(),mapa.end());
        Tree* t;
        initTree(freq,0,freq.size()-1,t);

        for(int i = 0;i<q;++i){
            scanf("%d %d",&l,&r);
            //printf("Q: %d %d\n",l,r);
            printf("%d\n",findMaxFreq(t,l,r));
        }
	}
	return 0;
}



