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

const LL inf = 1LL<<60;

int main(){
    int N;
    cin >> N;
    vector<vector<pair<int, LL> > > tree(N);
    REP(i, N-1){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        tree[a].push_back(make_pair(b, c));
        tree[b].push_back(make_pair(a, c));
    }
    int Q, K;
    cin >> Q >> K;
    K--;

    vector<LL> dist(N, inf);
    stack<int> st;
    dist[K] = 0;
    st.push(K);
    while(!st.empty()){
        int u = st.top();st.pop();
        REP(i, tree[u].size()){
            int v = tree[u][i].first;
            LL d = tree[u][i].second;
            if(dist[v]<inf)continue;
            dist[v] = dist[u] + d;
            st.push(v);
        }
    }
    REP(q, Q){
        int x, y;
        cin >> x >> y;
        x--;y--;
        cout << dist[x] + dist[y] << endl;
    }

    return 0;
}
