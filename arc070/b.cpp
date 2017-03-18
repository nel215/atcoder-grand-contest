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

int N, K;
vector<int> A;

bool is_need(int idx){
    if(idx<0)return false;
    if(idx>=N)return true;
    vector<int> dp(K);
    dp[0] = 1;
    REP(i, N){
        if(i==idx)continue;
        int a = A[i];
        for(int k=K-1; k>=a; k--){
            dp[k] |= dp[k-a];
        }
    }
    //cerr << idx << endl;
    //REP(k, K)cerr << dp[k];
    //cerr << endl;
    REP(k, K){
        if(dp[k] && k+A[idx]>=K)return true;
    }
    return false;
}

int solve(){
    cin >> N >> K;
    A.resize(N);
    REP(i, N)cin >> A[i];
    sort(ALL(A));

    int lb=-1;
    int ub=N;
    while(ub-lb>1){
        int mid = (lb+ub)>>1;
        if(is_need(mid)){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    return lb+1;
}

int main(){
    int res = solve();
    cout << res << endl;
    return 0;
}
