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


struct RMQ{
    int size;
    LL sum;
    vector<LL> data;
    RMQ(int n){
        size = 1;
        while(size < n)size *= 2;
        data.assign(2*size-1, 1LL<<60);
        sum = 0;
    }
    void update(int pos, LL val){
        pos += size-1;
        data[pos] = val - sum;
        while(pos>0){
            pos = (pos-1)>>1;
            data[pos] = min(data[2*pos+1], data[2*pos+2]);
        }
    }
    LL query(int a, int b, int k, int l, int r){
        if(b<=l || r<=a)return 1LL<<60;
        if(a<=l && r<=b)return data[k];
        int mid = (l+r)>>1;
        return min(query(a,b,2*k+1,l,mid), query(a,b,2*k+2,mid,r));
    }
    LL query(int left, int right){
        return query(left, right, 0, 0, size) + sum;
    }
    void add(LL val){
        sum += val;
    }
};

void update(RMQ &minus, RMQ &plus, int pos, LL val){
    minus.update(pos, val-pos);
    plus.update(pos, val+pos);
}

void add(RMQ &minus, RMQ &plus, LL val){
    minus.add(val);
    plus.add(val);
}

LL search(RMQ &minus, int N){
    LL res = 1LL<<62;
    REP(i, N){
        res = min(res, minus.query(i, i+1) + i);
    }
    return res;
}

int main(){
    int N, Q, A, B;
    cin >> N >> Q >> A >> B;
    A--;
    B--;
    RMQ minus = RMQ(N);
    RMQ plus = RMQ(N);
    int prev = B;
    update(minus, plus, A, 0);
    REP(i, Q){
        int x;
        cin >> x;
        x--;
        LL res = min(minus.query(0, x+1)+x, plus.query(x, N)-x);
        add(minus, plus, abs(prev-x));
        update(minus, plus, prev, res);
        prev = x;
    }
    cout << search(minus, N) << endl;
    return 0;
}
