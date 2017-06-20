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
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    int A = 1000;
    int B = -1000*(w*h-1)-1;
    vector<vector<int> > res(H, vector<int>(W, A));
    for(int y=h-1; y<H; y+=h){
        for(int x=w-1; x<W; x+=w){
            res[y][x] = B;
        }
    }
    vector<vector<int> > sum(H+1, vector<int>(W+1, 0));
    REP(y, H)REP(x, W){
        sum[y+1][x+1] = res[y][x] + sum[y+1][x] + sum[y][x+1] - sum[y][x];
    }

    bool ok = sum[H][W] > 0;
    //cerr << "sum: " << sum[H][W] << endl;
    REP(y, H)REP(x, W){
        if(y+h>H || x+w>W)continue;
        int s = sum[y+h][x+w] - sum[y+h][x] - sum[y][x+w] + sum[y][x];
        //printf("(%d,%d)-(%d,%d): %d\n", x, y, x+w, y+h, s);
        if(s>=0)ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    if(ok){
        REP(y, H)REP(x, W){
            cout << res[y][x] << (x==W-1 ? '\n' : ' ');
        }
    }

    return 0;
}
