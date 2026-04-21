#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100005;
const int LOG = 17;

int n, q;
vector<int> vecini[NMAX];

// HLD + LCA
int parinte[NMAX], adancime[NMAX], marime[NMAX], cap[NMAX], pozitie[NMAX], timp_intrare[NMAX];
int stramos[NMAX][LOG];
int contor = 0;

void dfs_marime(int nod, int par, int adanc) {
    parinte[nod] = par;
    adancime[nod] = adanc;
    marime[nod] = 1;
    stramos[nod][0] = par;
    for (int i = 1; i < LOG; i++)
        stramos[nod][i] = stramos[stramos[nod][i-1]][i-1];
    for (int vecin : vecini[nod]) {
        if (vecin != par) {
            dfs_marime(vecin, nod, adanc + 1);
            marime[nod] += marime[vecin];
        }
    }
}

void dfs_hld(int nod, int par, int capCurent) {
    cap[nod] = capCurent;
    pozitie[nod] = ++contor;
    timp_intrare[nod] = contor;
    int fiu_greu = -1;
    for (int vecin : vecini[nod]) {
        if (vecin != par && (fiu_greu == -1 || marime[vecin] > marime[fiu_greu]))
            fiu_greu = vecin;
    }
    if (fiu_greu == -1) return;
    dfs_hld(fiu_greu, nod, capCurent);
    for (int vecin : vecini[nod]) {
        if (vecin != par && vecin != fiu_greu)
            dfs_hld(vecin, nod, vecin);
    }
}

int lca(int u, int v) {
    if (adancime[u] < adancime[v]) swap(u, v);
    int diff = adancime[u] - adancime[v];
    for (int i = 0; i < LOG; i++)
        if ((diff >> i) & 1)
            u = stramos[u][i];
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--)
        if (stramos[u][i] != stramos[v][i]) {
            u = stramos[u][i];
            v = stramos[v][i];
        }
    return stramos[u][0];
}

// Arborele de intervale (Segment Tree) pentru numărare noduri comune
// Marcăm un interval [l, r] în pozițiile HLD și numărăm intersecțiile
// Folosim un vector lazy/adunare simplu: marcăm +1 pe intervalul unui drum,
// apoi întrebăm suma pe intervalul celuilalt drum.

int arbore[4 * NMAX];
int lazy[4 * NMAX];

void update(int nod, int st, int dr, int l, int r, int val) {
    if (r < st || dr < l) return;
    if (l <= st && dr <= r) {
        arbore[nod] += val * (dr - st + 1);
        lazy[nod] += val;
        return;
    }
    int mid = (st + dr) / 2;
    update(2*nod, st, mid, l, r, val);
    update(2*nod+1, mid+1, dr, l, r, val);
    arbore[nod] = arbore[2*nod] + arbore[2*nod+1] + lazy[nod] * (dr - st + 1);
}

int query(int nod, int st, int dr, int l, int r) {
    if (r < st || dr < l) return 0;
    if (l <= st && dr <= r) return arbore[nod];
    int mid = (st + dr) / 2;
    int stanga = query(2*nod, st, mid, l, r);
    int dreapta = query(2*nod+1, mid+1, dr, l, r);
    return stanga + dreapta + lazy[nod] * (max(l, st) <= min(r, dr) ? min(r, dr) - max(l, st) + 1 : 0);
}

// Resetăm arborele pe un drum
void marcheazaDrum(int u, int v, int val) {
    while (cap[u] != cap[v]) {
        if (adancime[cap[u]] < adancime[cap[v]]) swap(u, v);
        update(1, 1, n, pozitie[cap[u]], pozitie[u], val);
        u = parinte[cap[u]];
    }
    if (adancime[u] > adancime[v]) swap(u, v);
    update(1, 1, n, pozitie[u], pozitie[v], val);
}

int interogheazaDrum(int u, int v) {
    int rezultat = 0;
    while (cap[u] != cap[v]) {
        if (adancime[cap[u]] < adancime[cap[v]]) swap(u, v);
        rezultat += query(1, 1, n, pozitie[cap[u]], pozitie[u]);
        u = parinte[cap[u]];
    }
    if (adancime[u] > adancime[v]) swap(u, v);
    rezultat += query(1, 1, n, pozitie[u], pozitie[v]);
    return rezultat;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        vecini[u].push_back(v);
        vecini[v].push_back(u);
    }

    dfs_marime(1, 0, 0);
    dfs_hld(1, 0, 1);

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Marcăm drumul (a, b) cu +1
        marcheazaDrum(a, b, 1);

        // Numărăm câte noduri din drumul (c, d) sunt marcate
        int raspuns = interogheazaDrum(c, d);

        // Ștergem marcajul
        marcheazaDrum(a, b, -1);

        cout << raspuns << "\n";
    }

    return 0;
}
