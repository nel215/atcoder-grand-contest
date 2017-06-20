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

bool check(string s){
    int n = s.size();
    REP(i, n-1){
        if(s[i]!=s[i+1])return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    int res = 1<<30;
    int n = s.size();
    if(check(s))res = 0;
    for(char c='a'; c<='z'; c++){
        string t = s;
        REP(i, n){
            vector<char> w;
            REP(j, n-1-i){
                if(t[j]==c){
                    w.push_back(t[j]);
                }else{
                    w.push_back(t[j+1]);
                }
            }
            t = string(ALL(w));
            if(check(t)){
                res = min(res, i+1);
            }
        }
    }
    cout << res << endl;
    return 0;
}
