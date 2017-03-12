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
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    REP(i, N)cin >> T[i];

    sort(ALL(T));
    int res = 0;
    int ptr = 0;
    while(ptr<N){
        res++;
        int go = T[ptr] + K;
        int cnt = 0;
        while(ptr < N && cnt < C && T[ptr] <= go){
            cnt++;
            ptr++;
        }
    }

    cout << res << endl;

    return 0;
}
