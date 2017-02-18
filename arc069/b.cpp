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
    string s;
    cin >> N;
    cin >> s;

    // 0: S, 1: W
    REP(x, 2){
        REP(y, 2){
            bool check = true;
            vector<int> tmp(N, -1);
            tmp[0] = x;
            tmp[1] = y;
            REP(i, N){
                int j = (i+1) %N;
                int k = (i+2) %N;
                int c = s[j] == 'o';
                int next;
                if(tmp[j] == 0){
                    next = c ?tmp[i] : 1 - tmp[i];
                }else{
                    next = c ? 1 - tmp[i] : tmp[i];
                }
                if(tmp[k] != -1 && tmp[k] != next){
                    check = false;
                }
                tmp[k] = next;
            }
            if(check && tmp[0] == x && tmp[1] == y){
                string res;
                REP(i,N)res += "SW"[tmp[i]];
                cout << res << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
