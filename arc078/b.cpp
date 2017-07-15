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
    int N;
    cin >> N;
    vector<vector<int> > tree(N, vector<int>());
    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int f = 0, s = 0;
    queue<pair<int, int> > que;
    que.push(make_pair(0, 0));
    que.push(make_pair(1, N-1));
    vector<int> used(N);
    while(!que.empty()){
        pair<int, int> n = que.front();que.pop();
        if(used[n.second])continue;
        used[n.second] = 1;
        if(n.first==0)f++;
        if(n.first==1)s++;
        REP(i, tree[n.second].size()){
            int next = tree[n.second][i];
            if(used[next])continue;
            que.push(make_pair(n.first, next));
        }
    }
    cout << (f > s ? "Fennec" : "Snuke") << endl;

    return 0;
}
