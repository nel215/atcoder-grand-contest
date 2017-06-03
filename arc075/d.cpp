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

int N;
LL A, B;
vector<LL> hp;

bool check(LL c){
    LL res = 0;
    LL s = A-B;
    REP(i, N){
        LL h = hp[i] - c*B;
        if(h<=0)continue;
        res += h / s + (h%s==0 ? 0 : 1);
    }
    return res <= c;
}

int main(){
    cin >> N >> A >> B;
    hp.resize(N);
    REP(i, N)cin >> hp[i];
    LL lb = 0;
    LL ub = 1000000000;
    while(ub-lb>1){
        LL mid = (lb+ub)>>1;
        if(check(mid)){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    cout << ub << endl;
    return 0;
}
