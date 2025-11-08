#include <fstream>
using namespace std;
ifstream fin("rev.in");
ofstream fout("rev.out");
int n, m;
int v[100004];
int x, y, k;
struct query{
    int x, y, k;
}q[20004];
int rasp_poz(int k, int i){
    int poz = k;
    for(int j = i; j >= 1; j--){
        if(q[j].x <= poz && poz <= q[j].y){
            poz = q[j].x + q[j].y - poz;
        }
    }
    return poz;
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        v[i] = i;
    }
    for(int i = 1; i <= m; i++){
        fin >> q[i].x >> q[i].y >> q[i].k;
        fout << rasp_poz(q[i].k, i) <<'\n';
    }
    return 0;
}
