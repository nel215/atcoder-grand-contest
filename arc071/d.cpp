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

void modulo(LL &n){
    const int MOD = 1000000007;
    if(n >= MOD)n %= MOD;
}

int main(){
    LL N;
    cin >> N;
    vector<int> dp(N+1);
    vector<LL> sum(N+1);
    dp[1] = N;
    sum[1] = dp[1];
    for(int k=2; k<=N; k++){
        LL v = 0;
        // len(?????) is k
        // 1???????...
        v += dp[k-1];
        modulo(v);

        // cdddddd...d(c>1 and d>1)
        v += (N-1) * (N-1);
        modulo(v);

        // c11???... + c111???... + c11...? (c>1)
        // c=2, 3, 4,..., k-2
        if(k-3>=0){
            v += sum[k-3];
            modulo(v);
        }

        // c111...1111 (c>1)
        // c=N, N-1,..., k-1
        v += N - max(k-1, 2) + 1;
        modulo(v);

        // update
        dp[k] = v;
        sum[k] = sum[k-1] + dp[k];
        modulo(sum[k]);
    }
    //REP(i, N)cerr << dp[i] << endl;
    cout << dp[N] << endl;

    return 0;
}
