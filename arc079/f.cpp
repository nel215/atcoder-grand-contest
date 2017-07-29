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
vector<int> from;
vector<vector<int> > to;

int get_not_exist_min(const vector<int> &vec, const vector<int> &A, bool second=false){
    int n = vec.size();
    vector<int> children(n);
    REP(i, vec.size()){
        int v = vec[i];
        if(A[v]<0 || A[v]>=n)continue;
        children[A[v]] = 1;
    }
    int res = 0;
    while(res<n && children[res])res++;
    if(second){
        res++;
        while(res<n && children[res])res++;
    }
    return res;
}

void bfs(queue<int> que, vector<int> &visit, vector<int> &res){
    while(!que.empty()){
        int u = que.front();que.pop();
        res[u] = get_not_exist_min(to[u], res);
        int v = from[u];
        visit[v]++;
        if(visit[v]!=(int)to[v].size())continue;
        que.push(v);
    }
}

bool check(queue<int> que, vector<int> visit, vector<int> res){
    bfs(que, visit, res);
    bool ok = true;
    REP(u, N){
        vector<int> cnt(res[u]);
        REP(i, to[u].size()){
            int v = to[u][i];
            if(res[v]==res[u])ok = false;
            if(res[v]<res[u])cnt[res[v]]++;
        }
        REP(i, cnt.size()){
            if(cnt[i]==0)ok = false;
        }
    }
    return ok;
}

int main(){
    cin >> N;
    from.resize(N);
    to.assign(N, vector<int>());

    REP(i, N){
        int p;
        cin >> p;
        p--;
        from[i] = p;
        to[p].push_back(i);
    }
    vector<int> res(N, -1);
    queue<int> que;
    REP(i, N)if((int)to[i].size()==0)que.push(i);
    vector<int> visit(N);
    bfs(que, visit, res);

    bool ok = false;
    REP(i, N){
        if(res[i]==-1){
            queue<int> que;
            que.push(from[i]);
            int first = get_not_exist_min(to[i], res, false);
            int second = get_not_exist_min(to[i], res, true);
            res[i] = first;
            visit[i]++;
            if(check(que, visit, res))ok = true;
            res[i] = second;
            if(check(que, visit, res))ok = true;
            break;
        }
    }

    cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}
