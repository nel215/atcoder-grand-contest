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

struct Node{
    int v, c;
    Node(int v, int c){
        this->v = v;
        this->c = c;
    }
    Node(){
        this->v = 0;
        this->c = 0;
    }
};

int main(){
    LL N, M;
    cin >> N >> M;
    vector<vector<int> > G(N, vector<int>());
    REP(i, M){
        int u, v;
        cin >> u >> v;
        u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    LL ind = 0;
    LL bipartite = 0;
    LL not_bipartite = 0;
    vector<int> color(N, -1);
    REP(i, N){
        if(G[i].size()==0){
            ind++;
            continue;
        }
        if(color[i]!=-1)continue;
        //cerr << "start:" << i << endl;
        stack<Node> st;
        st.push(Node(i, 0));
        bool is_bipertite = true;
        while(!st.empty()){
            Node n = st.top();st.pop();
            if(color[n.v]!=-1){
                if(color[n.v]!=n.c)is_bipertite = false;
                continue;
            }
            color[n.v] = n.c;
            REP(j, G[n.v].size()){
                st.push(Node(G[n.v][j], 1-n.c));
            }
        }
        if(is_bipertite)bipartite++;
        else not_bipartite++;
    }

    LL res = ind*(2LL*N-ind);
    res += 2LL * bipartite * bipartite;
    res += 1LL * (not_bipartite * not_bipartite + 2LL * not_bipartite * bipartite);
    //cerr << "info:" << not_bipartite << " " << bipartite<< endl;

    cout << res << endl;

    return 0;
}
