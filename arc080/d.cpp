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
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> A(N);
    REP(i, N)cin >> A[i];
    vector<vector<int> > res(H, vector<int>(W, 0));
    int y = 0;
    int x = 0;
    REP(i, N){
        REP(j, A[i]){
            res[y][x] = i+1;
            x += 1 - 2*(y%2);
            if(x==W){x--;y++;}
            if(x==-1){x++;y++;}
        }
    }
    REP(i, H)REP(j, W)cout << res[i][j] << (j==W-1 ? '\n' : ' ');
    return 0;
}
