#include <fstream>
#include <map>
using namespace std;
ifstream fin("ausoara.in");
ofstream fout("ausoara.out");
int n, m;
int v[1004];
int f[1000004], ft[1000004];
int main(){
    fin >> n;
    for(int i = 1; i <= 1000000; i++){
        ft[i] = 1001;
    }
    for(int i = 1; i <= n; i++){
        fin >> m;
        for(int j = 1; j <= m; j++){
            fin >> v[j];
            f[v[j]]++;
        }
        for(int i = 1; i <= 1000000; i++){
            ft[i] = min(ft[i], f[i]);
            f[i] = 0;
        }
    }
    int rasp = 0;
    for(int i = 1; i <= 1000000; i++){
        rasp += ft[i];
    }
    fout << rasp << ' ';
    for(int i = 1; i <= 1000000; i++){
        while(ft[i]){
            ft[i]--;
            fout << i << ' ';
        }
    }
    return 0;
}
