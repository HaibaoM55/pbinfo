#include <fstream>
using namespace std;
ifstream fin("descfib.in");
ofstream fout("descfib.out");
int n;
int f[30];
int v[30];
void bt(int n, int vmax){
    if(n == 0){
        for(int i = 1; i <= v[0]; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
        return;
    }
    for(int i = vmax+1; f[i] <= n; i++){
        v[0]++;
        v[v[0]] = f[i];
        bt(n-f[i], i);
        v[0]--;
    }
}
int main(){
    fin >> n;
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= 28; i++){
        f[i] = f[i-1]+f[i-2];
    }
    bt(n, 1);
    return 0;
}
