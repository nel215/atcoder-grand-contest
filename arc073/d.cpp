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
    LL N, W;
    cin >> N >> W;
    vector<LL> w(N);
    vector<LL> v(N);
    REP(i, N){
        cin >> w[i] >> v[i];
    }
    LL base = w[0];
    REP(i, N)w[i] -= base;
    vector<vector<LL> > dp(N+1, vector<LL>(3*N+1, -INF));
    dp[0][0] = 0;
    REP(i, N){
        vector<vector<LL> > next(N+1, vector<LL>(3*N+1, -INF));
        REP(j, i+1){
            REP(k, 3*N+1){
                if(dp[j][k]==-INF)continue;
                // do not use
                next[j][k] = max(next[j][k], dp[j][k]);
                // use
                LL weight = k + w[i];
                LL value = dp[j][k] + v[i];
                if(base*(j+1) + weight <= W){
                    next[j+1][weight] = max(next[j+1][weight], value);
                }
            }
        }
        dp = next;
    }
    LL res = 0;
    REP(i, N+1)REP(j, 3*N+1)res = max(res, dp[i][j]);
    cout << res << endl;
    return 0;
}
