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

struct BIT{
    int N;
    vector<LL> data;
    BIT(int N){
        this->N = N;
        data.assign(N+1, 0);
    }
    void add(int i, LL v){
        while(i<=N){
            data[i] += v;
            i += i&-i;
        }
    }
    LL sum(int i){
        LL res = 0;
        while(i>0){
            res += data[i];
            i -= i&-i;
        }
        return res;
    }
};


int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i, N)cin >> A[i];

    vector<LL> B(N+1);
    REP(i, N){
        B[i+1] = B[i] + A[i] - K;
    }
    sort(ALL(B));
    BIT bit(N+1);
    LL res = 0;
    LL thres = 0;
    REP(i, N+1){
        int p = lower_bound(ALL(B), thres) - B.begin() + 1;
        res += bit.sum(p);
        bit.add(p, 1);
        thres += A[i] - K;
    }
    cout << res << endl;

    return 0;
}
