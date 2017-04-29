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
    int N, T;
    scanf("%d %d", &N, &T);
    vector<pair<int, int> > events(N);
    int res = 0;
    int prev_to = 0;
    REP(i, N){
        int from;
        scanf("%d", &from);
        int to = from + T;
        from = max(from, prev_to);
        res += to - from;
        prev_to = to;
    }
    printf("%d\n", res);
    return 0;
}
