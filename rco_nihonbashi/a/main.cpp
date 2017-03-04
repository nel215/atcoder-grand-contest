
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

struct State{
    int score;
    vector<int> history;
    State(int s, vector<int> history){
        score = s;
        history = history;
    }
    State(){
        score = 0;
        history = vector<int>();
    }
    bool operator<(const State &s)const{
        return this->score > s.score;
    }
};

struct Node{
    int pos;
    int score;
    int level;
    vector<int> history;
    Node(int p, int s){
        pos = p;
        score = s;
        history = vector<int>();
        history.push_back(p);
    }
    bool operator<(const Node &n)const{
        return this->score < n.score;
    }
};

int H, W, K;
vector<int> field;

bool valid(int y, int x){
    return y >=0 && x >= 0 && y < H && x < W;
}

int main(){
    double start_time = get_time();
    cin >> H >> W >> K;
    field.resize(H*W);
    REP(y, H){
        string row;
        cin >> row;
        REP(x, W){
            int p = y*W+x;
            int n = row[x]-'0';
            field[p] = n;
        }
    }

    vector<int> cand;
    for(int i=9; i>=0; i--){
        REP(p, H*W){
            if(field[p]!=i)continue;
            cand.push_back(p);
        }
    }

    vector<int> trash;
    State start(0, vector<int>());
    vector<State> beam;
    beam.push_back(start);
    int B = 800;
    for(int k=0;;k++){
        if(get_time()-start_time > 8.0){
            B = 300;
        }
        if(get_time()-start_time > 9.5){
            break;
        }
        vector<State> next_beam;
        sort(ALL(beam));
        if((int)beam.size()>B){
            beam.resize(B);
        }
        REP(i, beam.size()){
            State s = beam[i];
            // cerr << s.score << " " << s.history.size() << endl;

            vector<int> used(H*W);
            REP(j, s.history.size()){
                int p = s.history[j];
                used[p] = 1;
            }
            REP(j, trash.size()){
                used[trash[j]] = 1;
            }

            REP(j, cand.size()){
                int p = cand[j];
                if(used[p])continue;

                Node n(p, 1);
                priority_queue<Node> que;
                que.push(n);
                while(!que.empty()){
                    Node n = que.top();que.pop();
                    if(used[n.pos])continue;
                    used[n.pos] = 1;
                    if((int)n.history.size()==K){
                        State next_state = s;

                        int score = 1;
                        REP(m, K){
                            int hp = n.history[m];
                            next_state.history.push_back(hp);
                            score *= field[hp];
                        }
                        //cerr << score << endl;
                        next_state.score += score;
                        next_beam.push_back(next_state);
                        continue;
                    }
                    int cy = n.pos / W;
                    int cx = n.pos % W;
                    const int DY[4] = {-1, 0, 1, 0};
                    const int DX[4] = {0, -1, 0, 1};
                    REP(m, 4){
                        int ny = cy + DY[m];
                        int nx = cx + DX[m];
                        if(!valid(ny, nx))continue;

                        int np = ny*W+nx;
                        if(used[np])continue;
                        Node next_node = n;
                        next_node.pos = np;
                        next_node.score *= field[np];
                        next_node.history.push_back(np);
                        que.push(next_node);
                    }
                }
                if(next_beam.size()==0){
                    trash.push_back(p);
                    continue;
                }
                break;
            }


        }
        if(next_beam.size()==0)break;
        beam = next_beam;
    }
    sort(ALL(beam));
    State best = beam[0];
    cerr << (get_time() - start_time) << endl;
    cout << best.history.size()/K << endl;
    REP(i, best.history.size()){
        int p = best.history[i];
        int y = p / W;
        int x = p % W;
        cout << (y+1) << " " << (x+1) << endl;
    }

    return 0;
}
