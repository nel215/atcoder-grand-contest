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
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    pair<double, pair<int, int> > res = make_pair(-1, make_pair(-1, -1));
    for(int a=0; a*100*A<=F; a++){
        for(int b=0; a*100*A+b*100*B<=F; b++){
            int w = a*100*A+b*100*B;
            int max_suger = w/100*E;
            for(int c=0; w+c*C<=F && c*C<=max_suger; c++){
                for(int d=0; w+c*C+d*D<=F && c*C+d*D<=max_suger; d++){
                    int s = c*C+d*D;
                    if(w+s==0)continue;
                    res = max(res, make_pair(100.0*s/(w+s), make_pair(w+s, s)));
                }
            }
        }
    }
    cout << res.second.first << " " << res.second.second << endl;
    return 0;
}
