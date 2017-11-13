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
int Z, W;
vector<int> A;

int memo[2][2005];

int rec(int turn, int idx){
  if(memo[turn][idx]!=-1)return memo[turn][idx];
  int opp = idx==0 ? W : A[idx-1];
  int res = abs(opp-A[N-1]);
  for(int i=idx; i<N-1; i++){
    int tmp = rec(1-turn, i+1);
    if(turn==0){
      res = max(res, tmp);
    } else {
      res = min(res, tmp);
    }
  }
  return memo[turn][idx] = res;
}

int main(){
  memset(memo, -1, sizeof(memo));
  cin >> N >> Z >> W;
  A.resize(N);
  REP(i, N)cin >> A[i];
  cout << rec(0, 0) << endl;
}
