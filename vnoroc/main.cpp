#include <bits/stdc++.h>
using namespace std;
bool compat[8][8];
void precompute_compat() {
    auto g = [](int a, int b) -> int {
        while (b) { a %= b; swap(a,b); }
        return a;
    };
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 1 || j == 1) compat[i][j] = false;
            else if (i == 0 || j == 0) compat[i][j] = true;
            else compat[i][j] = (g(i,j) > 1);
        }
    }
}
namespace fastio {
    char ibuf[1<<22];
    int ipos = 0, ilen = 0;
    inline int gc() {
        if (ipos == ilen) {
            ilen = fread(ibuf, 1, sizeof(ibuf), stdin);
            ipos = 0;
        }
        return ipos < ilen ? ibuf[ipos++] : -1;
    }
    inline int ri() {
        int c, x = 0;
        while ((c = gc()) < '0');
        do x = x*10 + c-'0'; while ((c=gc()) >= '0');
        return x;
    }

    char obuf[1<<22];
    int opos = 0;
    inline void flush() { fwrite(obuf, 1, opos, stdout); opos = 0; }
    inline void pc(char c) {
        if (opos == sizeof(obuf)) flush();
        obuf[opos++] = c;
    }
    inline void wi(int x) {
        if (x >= 10) wi(x/10);
        pc('0'+x%10);
    }
}
int main(){
    freopen("vnoroc.in","r",stdin);
    freopen("vnoroc.out","w",stdout);
    precompute_compat();
    int C = fastio::ri();
    int N = fastio::ri();
    vector<int> a(N);
    for (int i = 0; i < N; i++) a[i] = fastio::ri();
    vector<short> dp(N);
    {
        int best[8] = {};
        for (int i = 0; i < N; i++) {
            int v = a[i];
            dp[i] = (short)(1 + best[v]);
            for (int d = 0; d < 8; d++)
                if (compat[d][v])
                    if (dp[i] > best[d]) best[d] = dp[i];
        }
    }

    int maxLen = *max_element(dp.begin(), dp.end());

    if (C == 1) {
        printf("%d\n", N - maxLen);
        return 0;
    }

    vector<short> dp2(N);
    {
        int best2[8] = {};
        for (int i = N-1; i >= 0; i--) {
            int v = a[i];
            dp2[i] = (short)(1 + best2[v]);
            for (int d = 0; d < 8; d++)
                if (compat[d][v])
                    if (dp2[i] > best2[d]) best2[d] = dp2[i];
        }
    }
    int sz = (N+1)*8;
    vector<short> suf(sz, 0);
    for (int i = N-1; i >= 0; i--) {
        int base = i*8;
        int base1 = (i+1)*8;
        for (int d = 0; d < 8; d++) suf[base+d] = suf[base1+d];
        int v = a[i];
        for (int d = 0; d < 8; d++) {
            if (compat[d][v]) {
                if (dp2[i] > suf[base+d]) suf[base+d] = dp2[i];
            }
        }
    }
    vector<int> positions[8];
    for (int i = 0; i < N; i++) positions[a[i]].push_back(i);
    bool first = true;
    int pos = 0, last = -1, remaining = maxLen;

    while (remaining > 0) {
        for (int d = 0; d < 8; d++) {
            if (last != -1 && !compat[last][d]) continue;

            auto& pv = positions[d];
            auto it = lower_bound(pv.begin(), pv.end(), pos);
            if (it == pv.end()) continue;
            int idx = *it;

            if (remaining == 1 || (idx+1 <= N && suf[(idx+1)*8+d] >= remaining-1)) {
                if (!first) fastio::pc(' ');
                fastio::wi(d);
                first = false;
                pos = idx+1;
                last = d;
                remaining--;
                break;
            }
        }
    }
    fastio::pc('\n');
    fastio::flush();

    return 0;
}
