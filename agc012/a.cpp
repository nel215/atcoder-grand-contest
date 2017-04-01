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
    vector<int> a(3*N);
    REP(i, 3*N)cin >> a[i];
    sort(ALL(a));
    reverse(ALL(a));
    LL res = 0;
    REP(i, N){
        res += a[2*i+1];
    }
    cout << res << endl;
    return 0;
}
