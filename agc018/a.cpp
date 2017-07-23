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

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i, N)cin >> A[i];
    int g = A[0];
    bool ok = false;
    REP(i, N)g = gcd(g, A[i]);
    REP(i, N){
        if(A[i]>=K && (A[i]%g) == (K%g))ok = true;
    }
    cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;

    return 0;
}
