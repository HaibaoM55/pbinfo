#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Road {
    int x, y, g, s;
};

int par[205], rnk[205];

int find(int x) {
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
}

bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    ll G, S;
    cin >> G >> S;

    vector<Road> roads(M);
    for (int i = 0; i < M; i++) {
        cin >> roads[i].x >> roads[i].y >> roads[i].g >> roads[i].s;
    }

    // Eliminam self-loops (nu contribuie la conexitate)
    // Le pastram totusi — Kruskal le va ignora automat (same component)

    // Sortam dupa g crescator
    vector<int> byG(M), byS(M);
    iota(byG.begin(), byG.end(), 0);
    iota(byS.begin(), byS.end(), 0);

    sort(byG.begin(), byG.end(), [&](int a, int b){
        return roads[a].g < roads[b].g;
    });
    sort(byS.begin(), byS.end(), [&](int a, int b){
        return roads[a].s < roads[b].s;
    });

    ll ans = LLONG_MAX;

    // available[i] = true daca drumul i e disponibil (gi <= a curent)
    vector<bool> available(M, false);

    int i = 0;
    while (i < M) {
        // Adaugam toate drumurile cu acelasi g
        int curG = roads[byG[i]].g;
        while (i < M && roads[byG[i]].g == curG) {
            available[byG[i]] = true;
            i++;
        }

        // Rulam Kruskal pe drumurile disponibile, sortate dupa s
        for (int v = 1; v <= N; v++) { par[v] = v; rnk[v] = 0; }

        int components = N;
        ll maxS = 0;

        for (int j = 0; j < M; j++) {
            int idx = byS[j];
            if (!available[idx]) continue;
            if (roads[idx].x == roads[idx].y) continue; // self-loop
            if (unite(roads[idx].x, roads[idx].y)) {
                components--;
                maxS = roads[idx].s;
                if (components == 1) break;
            }
        }

        if (components == 1) {
            ll cost = (ll)curG * G + maxS * S;
            ans = min(ans, cost);
        }
    }

    if (ans == LLONG_MAX) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
