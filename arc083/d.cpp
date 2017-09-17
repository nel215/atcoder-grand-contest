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

LL solve(){
    int N;
    cin >> N;
    vector<vector<LL> > D(N, vector<LL>(N));
    vector<vector<int> > nouse(N, vector<int>(N));
    REP(i, N)REP(j, N)cin >> D[i][j];
    LL res = 0;
    REP(k, N)REP(i, N)REP(j, N){
        if(D[i][j] > D[i][k]+D[k][j])return -1;
        if(i==k || j==k)continue;
        if(D[i][j] == D[i][k]+D[k][j])nouse[i][j] = nouse[j][i] = 1;

    }
    REP(i, N)REP(j, i){
        if(nouse[i][j])continue;
        res += D[i][j];
    }
    return res;
}

int main(){
    cout << solve() << endl;
    return 0;
}
