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
    LL K;
    cin >> K;
    int N = 50;
    vector<LL> A(N);

    int m = K % N;
    REP(i, m)A[i] = N-i;
    for(int i=m; i<N; i++){
        A[i] = i-m;
    }

    K -= m;
    K /= N;
    cout << N << endl;
    REP(i, N){
        cout << A[i]+K << (i==N-1 ? '\n' : ' ');
    }

    return 0;
}
