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

vector<int> psum(const string &s){
    vector<int> res(s.size()+1);
    REP(i, s.size()){
        res[i+1] = res[i] + (s[i]=='A');
    }
    return res;
}

int main(){
    int q;
    string S, T;
    cin >> S;
    cin >> T;
    vector<int> SP = psum(S);
    vector<int> TP = psum(T);
    cin >> q;
    REP(i, q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sa = SP[b] - SP[a-1];
        int sb = b-a+1 - sa;
        int ta = TP[d] - TP[c-1];
        int tb = d-c+1 - ta;
        if(sa < ta){
            int diff = ta-sa;
            sa += diff;
            sb += diff;
        }
        if(sb < tb){
            int diff = tb-sb;
            sa += diff;
            sb += diff;
        }
        if(sa > ta && sb > tb){
            int diff = min(sa-ta, sb-tb);
            sa -= diff;
            sb -= diff;
        }
        //cerr << sa << "," << sb << " " << ta << "," << tb << endl;
        int diff = (sa-ta) + (sb-tb);
        cout << (diff%3==0 ? "YES" : "NO") << endl;
    }
    return 0;
}
