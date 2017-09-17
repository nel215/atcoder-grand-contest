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

int N;
vector<vector<int> > tree;
vector<int> X;
vector<int> A;
const int inf = 1<<28;

void rec(int v){
    if(tree[v].size()==0){
        A[v] = 0;
        return;
    }

    vector<vector<int> > dp(tree[v].size()+1, vector<int>(X[v]+1, inf));
    dp[0][0] = 0;
    REP(i, tree[v].size()){
        int u = tree[v][i];
        rec(u);
        REP(j, X[v]+1){
            if(j+X[u]<=X[v]){
                dp[i+1][j+X[u]] = min(dp[i+1][j+X[u]], dp[i][j]+A[u]);
            }
            if(j+A[u]<=X[v]){
                dp[i+1][j+A[u]] = min(dp[i+1][j+A[u]], dp[i][j]+X[u]);
            }
        }
    }
    A[v] = *min_element(ALL(dp[tree[v].size()]));
}

int main(){
    cin >> N;
    tree.assign(N, vector<int>());
    X.resize(N);
    A.assign(N, inf);
    REP(i, N-1){
        int p;
        cin >> p;
        tree[p-1].push_back(i+1);
    }
    REP(i, N)cin >> X[i];
    rec(0);
    cout << ((*max_element(ALL(A))) == inf ? "IMPOSSIBLE" : "POSSIBLE") << endl;
    return 0;
}
