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
    vector<int> A(N);
    REP(i, N)cin >> A[i];

    vector<int> B(N+1);
    REP(i, N){
        B[A[i]]++;
        B[A[i]+1]++;
    }

    bool ok = false;
    REP(c, N+1){
        if(B[c]!=N)continue;
        int one_cat = 0;
        REP(i, N){
            if(A[i]+1==c)one_cat++;
        }
        int two_cat = N - one_cat;
        int rem_color = c - one_cat;
        //cerr << c << " " << one_cat << " " << two_cat << " " << rem_color << endl;
        if(two_cat==0 && rem_color==0)ok = true;
        if(two_cat==0 || rem_color==0)continue;
        if(rem_color < 0)continue;
        if(two_cat >= rem_color*2)ok = true;
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
