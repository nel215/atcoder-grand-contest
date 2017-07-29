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

    LL res = 0;
    while(true){
        bool end = true;
        vector<LL> add(N);
        REP(i, N){
            LL a = A[i] / N;
            if(a>0)end = false;
            res += a;
            REP(j, N){
                if(i==j)continue;
                add[j] += a;
            }
            A[i] = A[i] % N;
        }
        REP(i, N)A[i] += add[i];
        if(end)break;
    }
    cout << res << endl;

    return 0;
}
