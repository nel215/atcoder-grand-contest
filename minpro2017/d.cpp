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

const LL INF = 1LL<<60;
int N;
LL K;


struct Node{
    // max <-> +, + <-> *, a*x+b
    LL a, b;
    Node(LL a=0, LL b=0){
        this->a = a;
        this->b = b;
    }
    void debug(){
        cerr << "a: " << a << ", b: " << b << endl;
    }
};

Node go(const Node &a, const Node &b){
    return Node(a.a+b.a, max(a.a+b.b, a.b));
}

class SegTree{
    int size;
    vector<Node> data;
public:
    SegTree(vector<int> date){
        int n = date.size();
        size = 1;
        while(size < n)size = size<<1;
        data.assign(2*size-1, Node());
    };
    void update(int k, Node n){
        k += size-1;
        //cerr << "k: " << k << ", ";data[k].debug();
        data[k] = go(n, data[k]);
        //cerr << "k: " << k << ", ";data[k].debug();
        while(k>0){
            k = (k-1)>>1;
            data[k] = go(data[2*k+2], data[2*k+1]);
            //cerr << "k: " << k << ", ";data[k].debug();
        }
    }
    LL query(int a, int b){
        Node res = query(a, b, 0, 0, size);
        return max(res.a, res.b);
    }
    Node query(int a, int b, int k, int l, int r){
        if(b<=l || r<=a)return Node();
        if(a<=l && r<=b)return data[k];
        int mid = (l+r)>>1;
        Node res = go(query(a, b, 2*k+2, mid, r), query(a, b, 2*k+1, l, mid));
        // cerr << "k: " << k << ", ";res.debug();
        return res;
    }
};

struct Query{
    int type;
    LL date, order;
};

int main(){
    cin >> N >> K;
    vector<Query> query(N);
    vector<int> date(1, 0);
    REP(i, N){
        cin >> query[i].type;
        if(query[i].type==1){
            cin >> query[i].date >> query[i].order;
        }else{
            cin >> query[i].date;
        }
        date.push_back(query[i].date);
    }
    sort(ALL(date));
    date.erase(unique(ALL(date)), date.end());
    SegTree seg(date);
    REP(i, (int)date.size()-1){
        seg.update(i+1, Node(K*(date[i+1]-date[i]), 0));
    }
    REP(i, query.size()){
        Query q = query[i];
        int p = lower_bound(ALL(date), q.date) - date.begin();
        if(q.type==1){
            seg.update(p, Node(-q.order, 0));
        }else{
            LL res = seg.query(0, p+1);
            cout << (q.date*K - res) << endl;
        }
    }

    return 0;
}
