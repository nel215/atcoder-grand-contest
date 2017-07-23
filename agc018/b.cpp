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
    int N, M;
    cin >> N >> M;
    vector<vector<int> > A(N, vector<int>(M));
    REP(i, N){
        REP(j, M){
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    vector<int> score(M, 0);
    vector<int> pointer(N, 0);
    REP(i, N)score[A[i][0]]++;
    int res = 1<<30;
    REP(i, M){
        int idx = -1;
        int tmp = 0;
        REP(j, M){
            if(score[j]==-1)continue;
            if(idx==-1 || tmp<score[j]){
                tmp = score[j];
                idx = j;
            }
        }
        //cerr << tmp << endl;
        res = min(res, tmp);
        score[idx] = -1;
        REP(i, N){
            if(pointer[i]==M)continue;
            if(A[i][pointer[i]]==idx){
                while(pointer[i]<M && score[A[i][pointer[i]]]==-1)pointer[i]++;
                if(pointer[i]==M)continue;
                score[A[i][pointer[i]]]++;
            }
        }
    }
    //REP(i, N)cerr << "!" << pointer[i] << endl;
    cout << res << endl;
    return 0;
}
