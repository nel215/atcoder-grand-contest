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
    int N, M;
    cin >> N >> M;
    vector<int> from(N);
    vector<int> to(N);
    REP(i, M){
        int a, b;
        cin >> a >> b;
        a--;b--;
        if(a==0)from[b] = 1;
        if(b==N-1)to[a] = 1;
    }
    bool res = false;
    REP(i, N)if(from[i] && to[i])res = true;
    cout << (res ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}
