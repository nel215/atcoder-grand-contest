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

typedef vector<int> Edge;
typedef vector<Edge> Graph;

int N;
int A[100000];
Graph graph;
bool ok;

int rec(int v, int prev){
    int sum = 0;
    int mx = 0;
    REP(i, graph[v].size()){
        if(graph[v][i] == prev)continue;
        int c = rec(graph[v][i], v);
        sum += c;
        mx = max(mx, c);
    }
    if(sum == 0){
        return A[v];
    }
    int up = 2 * A[v] - sum;

    // check
    ok = ok && (up >= 0);
    ok = ok && (2*max(mx,up) <= up+sum);

    // cout << "v:" << v << ",A[v]:" << A[v] << ",up:" << up << ",ok:" << ok << endl;

    return up;
}

int main(){
    cin >> N;
    REP(i, N)cin >> A[i];
    graph.assign(N, Edge());
    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ok = true;
    int res = rec(0, -1);
    ok = ok && (res == (graph[0].size()==1 ? A[0] : 0));

    cout << (ok ? "YES" : "NO") << endl;

    return 0;
}
