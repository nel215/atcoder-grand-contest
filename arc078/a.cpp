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
    vector<LL> A(N);
    REP(i, N)cin >> A[i];
    LL lhs = 0;
    LL rhs = 0;
    LL res = 1LL<<62;
    REP(i, N)rhs += A[i];
    REP(i, N-1){
        lhs += A[i];
        rhs -= A[i];
        res = min(res, abs(lhs-rhs));
    }
    cout << res << endl;

    return 0;
}
