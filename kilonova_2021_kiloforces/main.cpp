#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define BLOC_SIZE 315
using namespace std;
int n, Q;
long long p[100005];
int t_val[100005];
int o[100005];
struct query{
    int l, r, idx;
    long long rasp;
}q[100005];
bool compara_mo(query a, query b){
    int block_a = a.l / BLOC_SIZE;
    int block_b = b.l / BLOC_SIZE;
    if(block_a != block_b) {
        return block_a < block_b;
    }
    if(block_a % 2 == 1) {
        return a.r < b.r;
    } else {
        return a.r > b.r;
    }
}
bool compara(query a, query b){
    return a.idx < b.idx;
}
int cnt[100005];
long long rasp = 0;
int l0 = 1, r0 = 0;
void add(int pos) {
    rasp += p[pos];
    int o1 = o[pos];
    int nrmm = 0;
    for(int i = o1 + 1; i <= n; i++){
        nrmm += cnt[i];
    }
    rasp -= 1LL * t_val[pos] * nrmm;
    for(int i = 1; i < o1; i++){
        if(cnt[i] > 0) {
            for (int j = l0; j <= r0; j++) {
                if (o[j] == i) {
                    rasp -= t_val[j];
                    break;
                }
            }
        }
    }
    cnt[o1]++;
}
void rmv(int pos) {
    rasp -= p[pos];
    int o1 = o[pos];
    int nrmm = 0;
    for(int i = o1 + 1; i <= n; i++){
        nrmm += cnt[i];
    }
    rasp += 1LL * t_val[pos] * nrmm;
    for(int i = 1; i < o1; i++) {
        if(cnt[i] > 0){
            for(int j = l0; j <= r0; j++){
                if(o[j] == i && j != pos){
                    rasp += t_val[j];
                    break;
                }
            }
        }
    }
    cnt[o1]--;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<pair<int, int>> perechi;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        t_val[i] = t;
        perechi.push_back({t, i});
    }
    sort(perechi.begin(), perechi.end());
    for(int i = 0; i < n; i++) {
        o[perechi[i].second] = i + 1;
    }
    for(int i = 1; i <= Q; i++){
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
    }
    sort(q+1, q + Q +1, compara_mo);
    for(int i = 1; i <= Q; i++) {
        int L = q[i].l;
        int R = q[i].r;
        while(r0 < R){
            add(++r0);
        }
        while(r0 > R){
            rmv(r0--);
        }
        while(l0 < L){
            rmv(l0++);
        }
        while(l0 > L){
            add(--l0);
        }
        q[i].rasp = rasp;
    }
    sort(q+1, q+Q+1, compara);
    for(int i = 1; i <= Q; i++){
        cout << q[i].rasp << '\n';
    }
    return 0;
}
