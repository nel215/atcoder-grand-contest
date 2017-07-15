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

#ifdef DEBUG
bool debug = true;
#else
bool debug = false;
#endif
int N;

string to_str(LL n){
    stringstream ss;
    ss << n;
    string s;
    ss >> s;
    return s;
}

bool query(LL n){
    if(debug){
        string s = to_str(n);
        string S = to_str(N);
        if(n <= N && s <= S)return true;
        if(n > N && s > S)return true;
        return false;
    }
    string ans;
    cout << "? " << n << endl;
    cin >> ans;
    return ans[0] == 'Y';
}

int solve(){
    if(query(1e9)){
        for(LL i=2; i<=1e10; i*=10){
            if(query(i))return i/2;
        }
        return -1;
    }
    for(LL len=1e9; len>1; len/=10){
        if(!query(len/10))continue;
        LL lb = len/10;
        LL ub = len-1;
        while(ub-lb>1){
            LL mid = (lb+ub)>>1;
            bool res = query(mid*10);
            cerr << lb << " " << ub << " " << mid << " " << res << endl;
            if(res){
                ub = mid;
            }else{
                lb = mid;
            }
        }
        return ub;
    }
    return -1;
}

int main(){
    if(debug){
        cin >> N;
    }
    int res = solve();
    cout << "! " << res << endl;
    return 0;
}

