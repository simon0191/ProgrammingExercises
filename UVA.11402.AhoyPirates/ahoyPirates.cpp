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

#define INV -1
#define FALSE 0
#define TRUE 1

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
void initTree(vector<bool>& freq,int l,int r,Tree* & t){
    t = new Tree(freq[l]?1:0,l,r,NULL,NULL);
    if(l == r){t->left = t->right = NULL;return;}
    int mid = (r+l)/2;
    initTree(freq,l,mid,t->left);
    initTree(freq,mid+1,r,t->right);
    t->freq = (t->left->freq + t->right->freq);
}
void bulkUpdate(int updateType,int l,int r,Tree* & t){
    switch (updateType){
        case FALSE:
            if(!t->freq)return;
        break;
        case TRUE:
            if(t->freq == (t->r-t->l+1))return;
        break;
    }
    if( (r == l) && ((t->l==l) && (t->r== r)) ){
        switch(updateType){
            case INV:t->freq = (t->freq?0:1);break;
            case FALSE:t->freq = 0;break;
            case TRUE:t->freq = 1;break;
        }
        return;
    }
    if((t->left->r >= l))bulkUpdate(updateType,l,min(t->left->r,r),t->left);
    if((t->right->l <= r))bulkUpdate(updateType,max(t->right->l,l),r,t->right);
    t->freq = (t->left->freq + t->right->freq);
    return ;
}
int rsq(Tree* t,int l,int r){
    if((t->l == l) && (t->r==r))return t->freq;
    int sumL = 0,sumR = 0;
    if((t->left->r >= l))sumL = rsq(t->left,l,min(t->left->r,r));
    if((t->right->l <= r))sumR = rsq(t->right,max(t->right->l,l),r);
    return (sumL+sumR);
}
int main(){
    int cases,n,rep,q,a,b;
    char buff[64];
    scanf("%d",&cases);
    vector<bool> v(1024100,0);
    char vv[1024100];
    for(int c = 1;c<=cases;++c){
        printf("Case %d:\n",c);
        scanf("%d",&n);
        int cont = 0;
        for(int i = 0 ;i<n;++i){
            scanf("%d %s",&rep,buff);
            for(int j = 0;j<rep;++j){
                for(int k = 0;buff[k];++k){
                    //v.push_back((buff[k]=='1')?true:false);
                    v[cont++] = ((buff[k]=='1')?1:0);
                }
            }
        }
        Tree* t;
        initTree(v,0,cont-1,t);
        int qs = 1;
        scanf("%d",&q);
        for(int i = 1;i<=q;++i){
            scanf("%s %d %d",buff,&a,&b);
            switch(buff[0]){
                case 'F':
                    bulkUpdate(TRUE,a,b,t);
                break;
                case 'E':
                    bulkUpdate(FALSE,a,b,t);

                break;
                case 'I':
                    bulkUpdate(INV,a,b,t);
                break;
                case 'S':
                    printf("Q%d: %d\n",qs++,rsq(t,a,b));
                break;
            }
        }
    }
	return 0;
}



