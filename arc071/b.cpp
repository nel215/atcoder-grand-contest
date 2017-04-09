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

const LL MOD = 1000000007LL;

LL row(const vector<int> &v){
    LL n = (int)v.size() - 1;
    LL res = 0;
    REP(i, n){
        LL k = i+1;
        LL w = v[i+1] - v[i];
        LL c = (k * (n-k+1)) % MOD;
        c = (c * w) % MOD;
        res = (res + c) % MOD;
    }
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<int> y(m);
    REP(i, n)cin >> x[i];
    REP(i, m)cin >> y[i];
    cout << (row(x) * row(y)) % MOD << endl;

    return 0;
}
