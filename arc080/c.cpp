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
    vector<int> B(3, 0);
    REP(i, N){
        int c = 0;
        while(A[i]%2==0){
            c++;
            A[i] /= 2;
        }
        c = min(2, c);
        B[c]++;
    }
    vector<int> C(N, -1);
    REP(i, B[0]){
        if(2*i>=N)continue;
        C[2*i] = 0;
    }
    REP(i, N){
        if(C[i]!=-1)continue;
        if(B[2]){
            C[i] = 2;
            B[2]--;
        }else if(B[1]){
            C[i] = 1;
            B[1]--;
        }
    }
    bool ok = true;
    REP(i, N-1){
        if(C[i]==-1 || C[i+1]==-1)ok = false;
        if(C[i]+C[i+1]<2)ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
