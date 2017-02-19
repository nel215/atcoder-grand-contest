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
#include <ctime>
#include <sys/time.h>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

const double TIME_LIMIT = 7.5;
double GetTime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec*1e-6;
}

const int N = 50;

bool need_to_search(char b){
    return b == 'x' || b == 'o';
}

bool valid_pos(int x, int y){
    return x >=0 && y >= 0 && x < N && y < N;
}

int score(const vector<string> &field){
    int x_score = 0;
    int o_score = 0;
    static int used[N*N];
    memset(used, 0, sizeof(used));

    REP(x, N)REP(y, N){
        int p = y*N + x;
        if(used[p]){
            continue;
        }
        char b = field[x][y];
        if(!need_to_search(b)){
            continue;
        }
        stack<int> st;
        st.push(p);
        int s = 0;
        while(!st.empty()){
            int cur = st.top();
            st.pop();
            s++;
            int cy = cur/N;
            int cx = cur%N;
            used[cur] = 1;
            const int DY[4] = {-1, 0, 1, 0};
            const int DX[4] = {0, -1, 0, 1};
            REP(i, 4){
                int ny = cy + DY[i];
                int nx = cx + DX[i];
                int nex = ny*N + nx;
                if(!valid_pos(nx, ny))continue;
                if(b != field[nx][ny] || used[nex])continue;
                st.push(nex);
            }

        }
        if(b == 'x')x_score = max(x_score, s);
        if(b == 'o')o_score = max(o_score, s);
    }

    return x_score + o_score;
}

void conv(const string &in, string &out){
    int r = 0;
    int p = 0;
    while(p<(int)in.size()){
        if(r >= (int)in.size()){
            out[p++] = '.';
        }else if(in[r] == 'x' || in[r] == 'o' || in[r] == '+'){
            out[p++] = in[r++];
        }else if(in[r] == '.'){
            r++;
        }else{
            if(r==p){
                out[p++] = in[r++];
            }else{
                out[p++] = '.';
            }
        }
    }
}

int xor128() {
  static int x = 123456789;
  static int y = 362436069;
  static int z = 521288629;
  static int w = 88675123;

  int t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

void test_conv(){
    string a = ".-x.o..-..+x";
    string b = "............";
    conv(a, b);
    cout << b << endl;
}

int main(){
    double now = GetTime();
    // test_conv();
    string S[N];
    REP(i, N)cin >> S[i];
    vector<string> lines(N, string(N, ' '));
    REP(x, N){
        REP(y, N){
            lines[x][y] = S[N-1-y][x];
        }
    }

    vector<pair<int, int> > cand;
    REP(x, N)REP(y, N){
        if(lines[x][y] == '.'){
            cand.push_back(make_pair(x, y));
        }
    }

    vector<string> out(N, string(N, ' '));
    REP(x, N)conv(lines[x], out[x]);
    int best_score = score(out);
    while(GetTime() - now < 1.0){
        pair<int, int> p = cand[xor128()%cand.size()];
        int px = p.first;
        int py = p.second;
        char old = lines[px][py];
        char b = "+-."[xor128()%3];
        if(b == lines[px][py])continue;
        lines[px][py] = b;
        conv(lines[px], out[px]);
        int s = score(out);
        //cout << s << endl;
        if(best_score < s){
            best_score = s;
        }else{
            lines[px][py] = old;
            conv(lines[px], out[px]);
        }
    }

    REP(y, N){
        REP(x, N)cout << lines[x][N-1-y];
        cout << endl;
    }
    // cout << best_score << endl;

    return 0;
}
