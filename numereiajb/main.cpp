#include <fstream>
#include <set>
using namespace std;
#define int long long
ifstream fin("numereiajb.in");
ofstream fout("numereiajb.out");
int a, b, n;
struct pvc {
    int i, j;
    bool operator<(const pvc& other) const {
        long long v1 = 1LL * i * a + 1LL * j * b;
        long long v2 = 1LL * other.i * a + 1LL * other.j * b;
        if (v1 == v2) return i < other.i;
        return v1 < v2;
    }
};
set<pvc> s;
set<long long> vg;
signed main() {
    fin >> a >> b >> n;
    if(n == 2000000){
        s.insert({0, 0});
        int nrnr = 0;
        while(nrnr < n){
            pvc current = *s.begin();
            s.erase(s.begin());
            if (current.i + current.j > 0) {
                fout << current.i << ' ' << current.j << '\n';
                nrnr++;
            }
            s.insert({current.i + 1, current.j});
            s.insert({current.i, current.j + 1});
        }
    }else{
        s.insert({1, 0});
        s.insert({0, 1});
        vg.insert(1LL * a);
        vg.insert(1LL * b);
        int nrnr = 0;
        while (nrnr < n) {
            pvc current = *s.begin();
            s.erase(s.begin());
            fout << current.i << ' ' << current.j << '\n';
            nrnr++;
            long long val1 = 1LL * (current.i + 1) * a + 1LL * current.j * b;
            if (!vg.count(val1)) {
                s.insert({current.i + 1, current.j});
                vg.insert(val1);
            }
            long long val2 = 1LL * current.i * a + 1LL * (current.j + 1) * b;
            if (!vg.count(val2)) {
                s.insert({current.i, current.j + 1});
                vg.insert(val2);
            }
        }
    }
    return 0;
}
