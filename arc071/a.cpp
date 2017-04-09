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
    int n;
    cin >> n;
    vector<string> S(n);
    REP(i, n){
        cin >> S[i];
    }
    string res = "";
    for(char c='a'; c<='z'; c++){
        int min_cnt = 1<<20;
        REP(i, n){
            int cnt = count(ALL(S[i]), c);
            min_cnt = min(min_cnt, cnt);
        }
        res += string(min_cnt, c);
    }
    cout << res << endl;
    return 0;
}
