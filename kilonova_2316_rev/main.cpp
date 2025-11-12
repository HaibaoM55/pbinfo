#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream  fin("rev.in");
ofstream fout("rev.out");
int n, m;
#define BLOC_SIZE 140
struct bloc {
    vector<int> v;
    bool rev = false;
};
vector<bloc> blocuri;
void build(){
    blocuri.clear();
    for(int i = 0; i < n; i += BLOC_SIZE){
        bloc b;
        for(int j = i; j < min(n, i + BLOC_SIZE); j++){
            b.v.push_back(j + 1);
        }
        blocuri.push_back(b);
    }
}
void push(int b) {
    if(blocuri[b].rev){
        reverse(blocuri[b].v.begin(), blocuri[b].v.end());
        blocuri[b].rev = false;
    }
}
void invers(int l, int r) {
    if (l >= r) return;
    int total = 0;
    int bl = -1, br = -1, offl = -1, offr = -1;
    for(int i = 0; i < (int)blocuri.size(); i++) {
        int sz = blocuri[i].v.size();
        if (bl == -1 && l <= total + sz) { bl = i; offl = l - total - 1; }
        if (r <= total + sz) { br = i; offr = r - total - 1; break; }
        total += sz;
    }
    if(bl == br) {
        push(bl);
        reverse(blocuri[bl].v.begin() + offl, blocuri[bl].v.begin() + offr + 1);
        return;
    }

    push(bl);
    vector<int> left_tail(blocuri[bl].v.begin() + offl, blocuri[bl].v.end());
    blocuri[bl].v.erase(blocuri[bl].v.begin() + offl, blocuri[bl].v.end());
    push(br);
    vector<int> right_head(blocuri[br].v.begin(), blocuri[br].v.begin() + offr + 1);
    blocuri[br].v.erase(blocuri[br].v.begin(), blocuri[br].v.begin() + offr + 1);
    reverse(blocuri.begin() + bl + 1, blocuri.begin() + br);

    for(int i = bl + 1; i < br; i++){
        blocuri[i].rev ^= 1;
    }

    reverse(left_tail.begin(), left_tail.end());
    reverse(right_head.begin(), right_head.end());
    blocuri[bl].v.insert(blocuri[bl].v.end(), right_head.begin(), right_head.end());
    blocuri[br].v.insert(blocuri[br].v.begin(), left_tail.begin(), left_tail.end());
}
int rasp_la_poz(int pos) {
    for(int i = 0; i < (int)blocuri.size(); i++){
        int sz = blocuri[i].v.size();
        if (pos <= sz) {
            if (!blocuri[i].rev) return blocuri[i].v[pos - 1];
            else return blocuri[i].v[sz - pos];
        }
        pos -= sz;
    }
    return -1;
}
int main() {
    fin >> n >> m;
    build();
    for (int q = 1; q <= m; q++) {
        int l, r, k;
        fin >> l >> r >> k;
        invers(l, r);
        fout << rasp_la_poz(k) << "\n";
    }
}
