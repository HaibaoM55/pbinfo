#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("prajituri.in");
ofstream fout("prajituri.out");
int n, m, vmax = 0;
long long vmaxb = 0;
int a[44];
struct sume{
    int suma;
    long long b;
}S[1048576+4];
bool compara(sume a, sume b){
    return a.suma < b.suma;
}
int z = 0;
int prmjum;
void bt1(int x, long long b1, int s){
    if(x == prmjum){
        z++;
        S[z].suma = s % m;
        S[z].b = b1;
        return;
    }
    bt1(x+1, b1, s);
    bt1(x+1, b1 | (1LL << x), s+a[x]);
}
void bt2(int x, long long b1, int s){
    if(x == n+1){
        s = s % m;
        int p1 = 1, p2 = z, p = 1;
        while(p1 <= p2){
            int mij = (p1 + p2)/2;
            if(S[mij].suma + s < m){
                p = mij;
                p1 = mij + 1;
            }else{
                p2 = mij - 1;
            }
        }
        if(S[p].suma + s < m && S[p].suma + s > vmax){
            vmax = S[p].suma + s;
            vmaxb = b1 | S[p].b;
        }
        if((S[z].suma + s) % m > vmax){
            vmax = (S[z].suma + s) % m;
            vmaxb = b1 | S[z].b;
        }
        return;
    }
    bt2(x+1, b1, s);
    bt2(x+1, b1 | (1LL << x), s+a[x]);
}
signed main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    prmjum = n/2+1;
    bt1(1, 0, 0);
    sort(S+1, S+z+1, compara);
    bt2(prmjum, 0, 0);
    fout << vmax << '\n';
    for(int i = 1; i <= n; i++){
        if(vmaxb & (1LL << i)){
            fout << 1;
        }else{
            fout << 0;
        }
    }
    fout << '\n';
    return 0;
}
