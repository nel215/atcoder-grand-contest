#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

const int inf = 1<<29;

struct SegTree{
    int size;
    vector<pair<int, int> > data;
    SegTree(const vector<int> &orig){
        size = 1;
        while(size<(int)orig.size())size = size<<1;
        data.assign(2*size-1, make_pair(inf, -1));
        REP(i,orig.size()){
            data[i+size-1] = make_pair(orig[i], i);
        }
        for(int i=size-2; i>=0; i--){
            data[i] = min(data[2*i+1], data[2*i+2]);
        }
    }
    pair<int,int> query(int a,int b)const{return query(a,b,0,0,size);}
    pair<int,int> query(int a,int b,int k,int l,int r)const{
        if(b<=l || r<=a)return make_pair(inf, -1);
        if(a<=l && r<=b)return data[k];
        int mid = (l+r)>>1;
        return min(query(a,b,2*k+1,l,mid),query(a,b,2*k+2,mid,r));
    }
};

struct Interval{
    int l, r;
    pair<int,int> p;
    Interval(int _l, int _r, pair<int,int> _p){
        this->l = _l;
        this->r = _r;
        this->p = _p;
    }
    bool operator<(const Interval &i)const{
        return this->p > i.p;
    }
};

pair<int,int> get(int l, int r, const SegTree &even, const SegTree &odd){
    return (l%2==0 ? even.query(l, r) : odd.query(l, r));
}

void push(int l, int r, priority_queue<Interval> &que, const SegTree &even, const SegTree &odd){
    if(l==r)return;
    pair<int,int> p = get(l, r, even, odd);
    que.push(Interval(l, r, p));
}

int main(){
    int N;
    cin >> N;
    vector<int> _even(N, inf);
    vector<int> _odd(N, inf);
    REP(i, N){
        int p;
        cin >> p;
        if(i%2==0){
            _even[i] = p;
        }else{
            _odd[i] = p;
        }
    }
    SegTree even(_even);
    SegTree odd(_odd);
    vector<int> res;
    priority_queue<Interval> que;
    que.push(Interval(0, N, even.query(0, N)));
    while(!que.empty()){
        Interval it = que.top();que.pop();
        int left = it.p.second;
        pair<int,int> p = get(left+1, it.r, even, odd);
        int right = p.second;
        push(it.l, left, que, even, odd);
        push(left+1, right, que, even, odd);
        push(right+1, it.r, que, even, odd);
        res.push_back(it.p.first);
        res.push_back(p.first);
    }
    REP(i, N)cout << res[i] << (i==N-1 ? '\n' : ' ');
    return 0;
}
