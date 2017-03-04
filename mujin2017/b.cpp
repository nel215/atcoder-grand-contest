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

int solve(){
    int N;
    vector<string> a;
    cin >> N;
    a.resize(N);
    REP(i,N)cin >> a[i];

    int white_sum = 0;
    int need_to_fill = 0;
    REP(x, N){
        int white = 0;
        REP(y, N){
            white += a[y][x] == '.';
        }
        white_sum += white;
        need_to_fill += white > 0;
    }
    if(white_sum == N*N)return -1;

    int res = 2*N;
    REP(y, N){
        int white = 0;
        REP(x, N){
            white += a[y][x] == '.';
        }
        int black = 0;
        REP(k, N){
            black += a[k][y]== '#';
        }
        if(black==0)white++;
        res = min(res, white + need_to_fill);
    }
    return res;
}

int main(){
    cout << solve() << endl;
    return 0;
}
