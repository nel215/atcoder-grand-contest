
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
#include <sys/time.h>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

double get_time(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec*1e-6;
}

using namespace std;

struct Feed{
    int score, dim;
};

struct State{
    int pos, spent, score;
    vector<int> history;
    bool operator<(const State &s)const{
        return this->score > s.score;
    }
};

struct Node{
    int pos, spent;
    vector<int> history;
};

int H, W, K, sr, sc;
int N;
vector<string> field;
vector<int> feed_id;
vector<Feed> feed;


bool valid(int y, int x){
    return y >=0 && x >= 0 && y < H && x < W;
}

char dir(int cp, int np){
    int cy = cp / W;
    int cx = cp % W;
    int ny = np / W;
    int nx = np % W;
    if(ny>cy)return 'U';
    if(ny<cy)return 'D';
    if(nx>cx)return 'R';
    if(nx<cx)return 'L';
    return '-';
}

int main(){
    double start_time = get_time();
    // field
    cin >> H >> W >> K >> sr >> sc;
    field.resize(H);

    REP(y, H){
        cin >> field[y];
    }

    // feed
    cin >> N;
    feed.resize(N);
    feed_id.assign(H*W, -1);
    REP(i, N){
        int y, x, F, D;
        cin >> y >> x >> F >> D;
        y--;x--;
        feed_id[y*W+x] = i;
        feed[i].score = F;
        feed[i].dim = D;
    }

    int B = 10;
    sr--;sc--;
    vector<vector<State> > beam(K+1);
    State start;
    int sp = sr*W+sc;
    start.pos = sp;
    start.history.push_back(sp);
    beam[0].push_back(start);
    REP(k, K){
        if(get_time() - start_time > 8.0){
            B = 1;
        }
        sort(ALL(beam[k]));
        if((int)beam[k].size() > B){
            beam[k].resize(B);
        }
        REP(i, beam[k].size()){
            State s = beam[k][i];
            // cout << "s: " << s.pos << " " << s.spent << " " << k << endl;

            vector<int> feed_used(H*W);
            REP(j, s.history.size()){
                int p = s.history[j];
                if(feed_id[p]>=0){
                    feed_used[p] = 1;
                }
            }

            vector<int> used(H*W, 0);
            queue<Node> que;
            Node start;
            start.pos = s.pos;
            start.spent = s.spent;
            que.push(start);
            while(!que.empty()){
                Node n = que.front();que.pop();
                //cout << "n: " << n.pos << " " << n.spent << " " << k << endl;
                if(n.spent>K)continue;
                if(used[n.pos])continue;
                used[n.pos] = 1;
                bool found = false;
                if(feed_used[n.pos]==0 && feed_id[n.pos]>=0){
                    Feed f = feed[feed_id[n.pos]];
                    int score = f.score - f.dim*n.spent;
                    //cout << score << endl;
                    if(score > 0){
                        // push state
                        State next_s = s;
                        next_s.pos = n.pos;
                        next_s.score += score;
                        next_s.spent = n.spent;

                        REP(j, n.history.size()){
                            next_s.history.push_back(n.history[j]);
                        }
                        beam[n.spent].push_back(next_s);
                        found = true;
                    }
                }
                if(found)continue;
                int cy = n.pos / W;
                int cx = n.pos % W;
                const int DY[4] = {-1, 0, 1, 0};
                const int DX[4] = {0, -1, 0, 1};
                REP(j, 4){
                    int ny = cy + DY[j];
                    int nx = cx + DX[j];
                    if(!valid(ny, nx))continue;
                    if(field[ny][nx]=='#')continue;
                    // cout << ny << " " << nx << endl;

                    int np = ny*W + nx;
                    if(used[np])continue;
                    Node next_n = n;
                    next_n.pos = np;
                    next_n.spent++;
                    next_n.history.push_back(np);
                    que.push(next_n);
                }
            }
        }
    }

    REP(k, K){
        int i = K-k;
        if(beam[i].size()==0)continue;
        sort(ALL(beam[i]));
        State best = beam[i][0];
        string res = "";
        REP(j, (int)best.history.size()-1){
            int cp = best.history[j];
            int np = best.history[j+1];
            res += dir(cp, np);
        }
        while((int)res.size() < K)res += "-";
        cerr << res.size() << endl;
        cout << res << endl;
        break;
    }

    return 0;
}
