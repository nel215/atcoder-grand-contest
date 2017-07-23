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

vector<LL> go(vector<pair<int, int> > &order, vector<int> &a, vector<int> &b, int T){
    int n = order.size();
    vector<LL> res(n+1, 0);
    priority_queue<int> que;
    REP(i, n){
        int idx = order[i].second;
        res[i+1] = res[i] + a[idx];
        que.push(b[idx]-a[idx]);
        if((int)que.size()>T){
            res[i+1] += que.top();
            que.pop();
        }
    }
    return res;
}

int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int N = X+Y+Z;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    vector<pair<int, int> > order(N);
    REP(i, N){
        cin >> A[i] >> B[i] >> C[i];
        int cost = A[i] - B[i];
        order[i] = make_pair(cost, i);
    }
    sort(ALL(order));

    vector<LL> sum1 = go(order, B, C, Y);
    reverse(ALL(order));
    vector<LL> sum2 = go(order, A, C, X);
    reverse(ALL(sum2));
    LL res = 0;
    for(int k=Y; k<=Y+Z; k++){
        res = max(res, sum1[k] + sum2[k]);
    }
    cout << res << endl;

    return 0;
}
