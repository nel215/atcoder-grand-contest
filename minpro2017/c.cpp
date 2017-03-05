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
    int N, K;
    cin >> N >> K;
    vector<int> req(N);
    REP(i, K){
        int a;
        cin >> a;
        a--;
        req[a] = 1;
    }
    vector<string> S(N);
    string max_req = "";
    REP(i, N){
        cin >> S[i];
        if(!req[i])continue;
        if(max_req.size() < S[i].size()){
            max_req = S[i];
        }
    }

    queue<int> que;
    REP(i, N){
        que.push(i);
    }
    string res = "";
    int satisfy = N;
    bool ok = true;
    REP(idx, max_req.size()){
        // cerr << ok << " " << satisfy << " " << expire.size() << " " << que.size() << endl;
        if(satisfy==K || !ok)break;

        queue<int> nque;
        char c = max_req[idx];
        while(!que.empty()){
            int i = que.front();que.pop();
            if(idx==(int)S[i].size() || S[i][idx]!=c){
                satisfy--;
                if(req[i])ok = false;
            }else{
                nque.push(i);
            }
        }
        if(satisfy<K)ok = false;
        que = nque;
        res += c;
    }
    ok = ok && (satisfy == K);
    cout << (ok ? res : "-1") << endl;
    return 0;
}
