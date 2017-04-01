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
Graph graph;

struct Query{
    int v, d, c;
};

void solve(){
    int N, M, Q;
    cin >> N >> M;
    graph.assign(N, Edge());
    REP(i, M){
        int a, b;
        cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> Q;
    vector<Query> query(Q);
    REP(i, Q){
        int v, d, c;
        cin >> v >> d >> c;
        v--;
        query[i].v = v;
        query[i].d = d;
        query[i].c = c;

    }
    reverse(ALL(query));

    vector<int> res(N);
    vector<vector<int> > used(N, vector<int>(11));
    REP(i, Q){
        queue<pair<int, int> > que;
        que.push(make_pair(query[i].v, query[i].d));
        while(!que.empty()){
            pair<int,int> node = que.front();que.pop();
            int v = node.first;
            int d = node.second;
            if(used[v][d])continue;
            used[v][d] = 1;
            if(res[v]==0)res[v] = query[i].c;
            if(d-1<0)continue;
            REP(j, graph[v].size()){
                int u = graph[v][j];
                if(used[u][d-1])continue;
                que.push(make_pair(u, d-1));
            }
        }
    }

    REP(i, N)cout << res[i] << endl;
}

int main(){
    solve();
    return 0;
}
