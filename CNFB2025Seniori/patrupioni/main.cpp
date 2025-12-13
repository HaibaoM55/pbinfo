#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

ifstream fin("patrupioni.in");
ofstream fout("patrupioni.out");

struct State{
    int w1l, w1c, w2l, w2c;
    int b1l, b1c, b2l, b2c;
    int turn;

    bool operator<(const State& o) const{
        if(w1l != o.w1l) return w1l < o.w1l;
        if(w1c != o.w1c) return w1c < o.w1c;
        if(w2l != o.w2l) return w2l < o.w2l;
        if(w2c != o.w2c) return w2c < o.w2c;
        if(b1l != o.b1l) return b1l < o.b1l;
        if(b1c != o.b1c) return b1c < o.b1c;
        if(b2l != o.b2l) return b2l < o.b2l;
        if(b2c != o.b2c) return b2c < o.b2c;
        return turn < o.turn;
    }
};

map<State, int> memo;

int solve(State s){
    if(s.w1l > s.w2l || (s.w1l == s.w2l && s.w1c > s.w2c)){
        swap(s.w1l, s.w2l);
        swap(s.w1c, s.w2c);
    }
    if(s.b1l > s.b2l || (s.b1l == s.b2l && s.b1c > s.b2c)){
        swap(s.b1l, s.b2l);
        swap(s.b1c, s.b2c);
    }

    if(memo.count(s)) return memo[s];

    int wcnt = (s.w1l > 0) + (s.w2l > 0);
    int bcnt = (s.b1l > 0) + (s.b2l > 0);

    if(wcnt == 0) return memo[s] = 2;
    if(bcnt == 0) return memo[s] = 1;

    bool canMove = false;
    int bestOutcome = (s.turn == 0) ? 2 : 1;

    if(s.turn == 0){
        for(int p = 0; p < 2; p++){
            int l = (p == 0) ? s.w1l : s.w2l;
            int c = (p == 0) ? s.w1c : s.w2c;
            if(l == 0) continue;

            if(l < 7){
                int nl = l + 1;
                bool blocked = (nl == s.w1l && c == s.w1c) || (nl == s.w2l && c == s.w2c) ||
                               (nl == s.b1l && c == s.b1c) || (nl == s.b2l && c == s.b2c);
                if(!blocked){
                    State ns = s;
                    if(p == 0) ns.w1l = nl; else ns.w2l = nl;
                    ns.turn = 1;
                    canMove = true;
                    int res = solve(ns);
                    if(res == 1){ bestOutcome = 1; break; }
                }
            }

            for(int dc = -1; dc <= 1; dc += 2){
                if(l < 7){
                    int nl = l + 1, nc = c + dc;
                    if(nc >= 1 && nc <= 3){
                        State ns = s;
                        if(nl == s.b1l && nc == s.b1c){
                            ns.b1l = 0; ns.b1c = 0;
                            if(p == 0){ ns.w1l = nl; ns.w1c = nc; }
                            else{ ns.w2l = nl; ns.w2c = nc; }
                            ns.turn = 1;
                            canMove = true;
                            int res = solve(ns);
                            if(res == 1){ bestOutcome = 1; break; }
                        }
                        if(nl == s.b2l && nc == s.b2c){
                            ns.b2l = 0; ns.b2c = 0;
                            if(p == 0){ ns.w1l = nl; ns.w1c = nc; }
                            else{ ns.w2l = nl; ns.w2c = nc; }
                            ns.turn = 1;
                            canMove = true;
                            int res = solve(ns);
                            if(res == 1){ bestOutcome = 1; break; }
                        }
                    }
                }
            }
            if(bestOutcome == 1) break;
        }
    }else{
        for(int p = 0; p < 2; p++){
            int l = (p == 0) ? s.b1l : s.b2l;
            int c = (p == 0) ? s.b1c : s.b2c;
            if(l == 0) continue;

            if(l > 1){
                int nl = l - 1;
                bool blocked = (nl == s.w1l && c == s.w1c) || (nl == s.w2l && c == s.w2c) ||
                               (nl == s.b1l && c == s.b1c) || (nl == s.b2l && c == s.b2c);
                if(!blocked){
                    State ns = s;
                    if(p == 0) ns.b1l = nl; else ns.b2l = nl;
                    ns.turn = 0;
                    canMove = true;
                    int res = solve(ns);
                    if(res == 2){ bestOutcome = 2; break; }
                }
            }

            for(int dc = -1; dc <= 1; dc += 2){
                if(l > 1){
                    int nl = l - 1, nc = c + dc;
                    if(nc >= 1 && nc <= 3){
                        State ns = s;
                        if(nl == s.w1l && nc == s.w1c){
                            ns.w1l = 0; ns.w1c = 0;
                            if(p == 0){ ns.b1l = nl; ns.b1c = nc; }
                            else{ ns.b2l = nl; ns.b2c = nc; }
                            ns.turn = 0;
                            canMove = true;
                            int res = solve(ns);
                            if(res == 2){ bestOutcome = 2; break; }
                        }
                        if(nl == s.w2l && nc == s.w2c){
                            ns.w2l = 0; ns.w2c = 0;
                            if(p == 0){ ns.b1l = nl; ns.b1c = nc; }
                            else{ ns.b2l = nl; ns.b2c = nc; }
                            ns.turn = 0;
                            canMove = true;
                            int res = solve(ns);
                            if(res == 2){ bestOutcome = 2; break; }
                        }
                    }
                }
            }
            if(bestOutcome == 2) break;
        }
    }

    if(!canMove){
        if(wcnt > bcnt) return memo[s] = 1;
        if(bcnt > wcnt) return memo[s] = 2;
        return memo[s] = (s.turn == 0) ? 2 : 1;
    }

    return memo[s] = bestOutcome;
}

int main(){
    int T;
    fin >> T;

    while(T--){
        State s;
        fin >> s.w1l >> s.w1c >> s.w2l >> s.w2c;
        fin >> s.b1l >> s.b1c >> s.b2l >> s.b2c;
        s.turn = 0;
        fout << solve(s) << " ";
    }
    return 0;
}
