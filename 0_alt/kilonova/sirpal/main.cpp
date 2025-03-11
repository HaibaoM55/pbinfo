#include <fstream>
#include <bitset>
using namespace std;
ifstream fin("sirpal.in");
ofstream fout("sirpal.out");
int a[1000001],mars[1000001];
bitset<1000001> bs;
pair<int,int> vf[1000001];
int main() {
    int n, minim = 1000000, maxim = -1000000;
    fin >> n;
    for(int i = 1;i <= n;i++) {
        fin >> a[i];
        minim = min(minim , a[i]);
        maxim = max(maxim, a[i]);
        if(bs[a[i]] == 0) {
            vf[a[i]].first = i;
            bs[a[i]] = 1;
        }else {
            vf[a[i]].second = i;
        }
    }
    for(int i = minim;i <= maxim;i++) {
        if(vf[i].second - vf[i].first > 1) {
            mars[vf[i].first + 1]++;
            mars[vf[i].second]--;
        }
    }
    for(int i = 1;i <= n;i++) {
        mars[i] = mars[i-1] + mars[i];
        if(mars[i] > 0){
            fout << 1;
        }else{
            fout << 0;
        }
    }
}
