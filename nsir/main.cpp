#include <fstream>
using namespace std;
ifstream fin("nsir.in");
ofstream fout("nsir.out");
int n;
int v[78];
bool exista = false;
void nsir(int vmax, double r, int m){
    if(-1 <= r  && r <= 1 && m == 0){
        exista = true;
        for(int i = 1; i <= v[0]; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
        return;
    }
    if(r < 0) return;
    for(int i = vmax; i <= m; i++){
        v[0]++;
        v[v[0]] = i;
        nsir(i, r-(100000.0/i), m-i);
        v[0]--;
    }
}
int main(){
    fin >> n;
    nsir(1, 100000, n);
    if(!exista){
        fout << 0;
    }
    return 0;
}
