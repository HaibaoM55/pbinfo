#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
ifstream fin("mere.in");
ofstream fout("mere.out");
set<int> s1;
unordered_map<int, int> pos;
vector<int> cer, val, sol;
int vx[200004], vy[200004];
int n, m, q;
int x, y;
int cp, cnt;
int p1, p2;
void ud(int st, int dr, int add)
{
     p1 = lower_bound(val.begin() + 1, val.begin() + cnt + 1, st) - val.begin();
     p2 = upper_bound(val.begin() + 1, val.begin() + cnt + 1, dr) - val.begin();
     sol[p1] += add;
     sol[p2] -= add;
}
int main()
{
    fin >> n >> m >> q;
    for (int i = 1; i <= m; i++){
        fin >> vx[i] >> vy[i];
    }
    cer = vector<int>(q + 4);
    for (int i = 1; i <= q; i++){
        fin >> cer[i];
        s1.insert(cer[i]);
    }
    val = vector<int>(q + 4);
    sol = vector<int>(q + 4);
    for (int x : s1)
    {
        cnt++;
        val[cnt] = x;
        pos[x] = cnt;
    }
    for (int i = 1; i <= m; ++i)
    {
        x = vx[i];
        y = vy[i];
        if (x + y - 1 < n){
            ud(x, x + y - 1, 1);
        }else{
            ud(x, n, 1);
            y = y-n+x-1;
            ud(1, n, y / n);
            y = y%n;
            if (y > 0){
                ud(1, y, 1);
            }
        }
    }
    for (int i = 1; i <= cnt; i++){
        sol[i] += sol[i - 1];
    }
    for (int i = 1; i <= q; i++){
        fout << sol[pos[cer[i]]] << ' ';
    }
    return 0;
}
