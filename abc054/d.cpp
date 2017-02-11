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


int main(){
    const int INF = 1<<28;
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<int> D(N);
    vector<int> c(N);
    REP(i,N){
        int a, b;
        cin >> a >> b >> c[i];
        a *= Mb;
        b *= Ma;
        D[i] = a - b;
    }

    map<int, int> memo;

    int res = INF;
    int m = N/2;
    REP(i, 1<<m){
        if(i==0)continue;
        int sum_d = 0;
        int sum_c = 0;
        REP(j, m){
            if((i>>j)&1){
                sum_d += D[j];
                sum_c += c[j];
            }
        }
        if(sum_d==0)res = min(res, sum_c);
        sum_d = -sum_d;
        if(memo.count(sum_d) == 0){
            memo[sum_d] = INF;
        }
        memo[sum_d] = min(memo[sum_d], sum_c);
    }

    int L = N - m;
    REP(i, 1<<L){
        if(i==0)continue;
        int sum_d = 0;
        int sum_c = 0;
        REP(j, L){
            if((i>>j)&1){
                int k = m + j;
                sum_d += D[k];
                sum_c += c[k];
            }
        }
        if(sum_d==0)res = min(res, sum_c);
        if(memo.count(sum_d) == 0){
            continue;
        }
        // cout << i << " " << sum_d << endl;
        res = min(res, memo[sum_d] + sum_c);
    }

    cout << (res == INF ? -1 : res) << endl;

    return 0;
}
