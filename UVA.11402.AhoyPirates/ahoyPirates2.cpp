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

#define MIX -2
#define INV -1
#define FALSE 0
#define TRUE 1

const int AZ_SIZE = 'Z'-'A'+1;

using namespace std;

struct Tree{
    int freq,l,r,state;
    bool leftUpToDate,rightUpToDate;
    int op;
    Tree *left,*right;
    Tree(){left = right = NULL;}
    Tree(int _freq,int _l,int _r,Tree* _left,Tree* _right,
         int _state):
        freq(_freq),l(_l),r(_r),left(_left),right(_right),
        state(_state){}
    bool isLeaf(){
        return ((left == NULL) && (right == NULL));
    }
};
void initTree(bitset<1024100>& freq,int l,int r,Tree* & t){
    t = new Tree(freq[l]?1:0,l,r,NULL,NULL,MIX);
    t->leftUpToDate = t->rightUpToDate = true;
    if(l == r){
        t->left = t->right = NULL;
        t->state = ( freq[l]?TRUE:FALSE);
        return;
    }
    int mid = (r+l)/2;
    initTree(freq,l,mid,t->left);
    initTree(freq,mid+1,r,t->right);
    t->freq = (t->left->freq + t->right->freq);
    t->state = ( (t->left->state==t->right->state)?t->left->state:MIX );
}
int bulkUpdate(int updateType,int l,int r,Tree* & t){
    switch (updateType){
        case FALSE:
            if(!t->freq)return 0;
        break;
        case TRUE:
            if(t->freq == (t->r-t->l+1))return t->freq;
        break;
    }
    if(  ((t->l==l) && (t->r== r)) ){
        switch(updateType){
            case INV:
                t->freq = ((r-l+1)-(t->freq));
                switch(t->state){
                    case TRUE:t->state=FALSE;break;
                    case FALSE:t->state=TRUE;break;
                }
            break;
            case FALSE:
                t->freq = 0;
                t->state = FALSE;
            break;
            case TRUE:
                t->freq = (r-l+1);
                t->state = TRUE;
            break;
        }
        t->leftUpToDate = t->rightUpToDate = (r==l);
        t->op = updateType;
        return t->freq;
    }
    if(!t->leftUpToDate){
        bulkUpdate(t->op,t->left->l,t->left->r,t->left);
        t->leftUpToDate = true;
    }
    if(!t->rightUpToDate){
        bulkUpdate(t->op,t->right->l,t->right->r,t->right);
        t->rightUpToDate = true;
    }
    if((t->left->r >= l)){
        bulkUpdate(updateType,l,min(t->left->r,r),t->left);
    }
    if((t->right->l <= r)){
        bulkUpdate(updateType,max(t->right->l,l),r,t->right);
    }
    t->state = ( (t->left->state==t->right->state)?t->left->state:MIX );
    t->freq = (t->left->freq + t->right->freq);
    return t->freq;
}
int rsq(Tree* t,int l,int r){
    if((t->l == l) && (t->r==r))return t->freq;
    int sumL = 0,sumR = 0;
    if(!t->leftUpToDate){
        bulkUpdate(t->op,t->left->l,t->left->r,t->left);
        t->leftUpToDate = true;
    }
    if(!t->rightUpToDate){
        bulkUpdate(t->op,t->right->l,t->right->r,t->right);
        t->rightUpToDate = true;
    }
    if((t->left->r >= l)){
        sumL = rsq(t->left,l,min(t->left->r,r));
    }
    if((t->right->l <= r)){
        sumR = rsq(t->right,max(t->right->l,l),r);
    }
    return (sumL+sumR);
}
int main(){
    int cases,n,rep,q,a,b;
    char buff[64];
    scanf("%d",&cases);
    //vector<bool> v(1024100,0);
    bitset<1024100> v;
    //char vv[1024100];
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
        /*
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
        }*/
    }
	return 0;
}




