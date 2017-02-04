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

LL N;
LL A[100000];
LL B[100000];

bool solve(){
    cin >> N;
    REP(i, N){
        cin >> A[i];
    }

    LL sum = 0;
    LL unit = N*(N+1LL)/2LL;
    REP(i, N)sum += A[i];

    if((sum % unit) != 0){
        return false;
    }

    LL loop = sum / unit;
    LL life = loop;

    REP(i, N){
        LL b = A[i] - A[(i+1)%N] + loop;
        if(b < 0)return false;
        if((b % N) != 0)return false;
        life -= b / N;
    }
    return life == 0;
}

int main(){
    cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}
