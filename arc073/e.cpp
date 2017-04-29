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

LL eval(const set<pair<int, int> > &red, const set<pair<int, int> > &blue){
    LL r = red.rbegin()->first - red.begin()->first;
    LL b = blue.rbegin()->first - blue.begin()->first;
    return r * b;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int, int> > xy(N);
    REP(i, N){
        int x, y;
        cin >> x >> y;
        xy[i] = make_pair(min(x, y), max(x, y));
    }
    sort(ALL(xy));
    set<pair<int, int> > red;
    set<pair<int, int> > blue;
    REP(i, N){
        red.insert(make_pair(xy[i].first, i));
        blue.insert(make_pair(xy[i].second, i));
    }
    LL res = eval(red, blue);
    REP(i, N){
        red.erase(make_pair(xy[i].first, i));
        blue.erase(make_pair(xy[i].second, i));
        red.insert(make_pair(xy[i].second, i));
        blue.insert(make_pair(xy[i].first, i));
        res = min(res, eval(red, blue));
    }
    cout << res << endl;
    return 0;
}
