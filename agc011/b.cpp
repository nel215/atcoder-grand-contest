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
    sort(ALL(A));

    vector<LL> B(N+1);
    REP(i,N){
        B[i+1] = B[i] + A[i];
    }

    int last = A[N-1];
    vector<int> eat(N);
    REP(i,N){
        int j = N-1-i;
        int p = upper_bound(ALL(A), B[j+1]*2) - A.begin();
        //cerr << p << "," << A[p-1] << "," << eat[p-1] << endl;
        if(last <= B[p] || eat[p-1])eat[j] = 1;
    }

    int res = 0;
    REP(i, N)res += eat[i];
    cout << res << endl;

    return 0;
}
