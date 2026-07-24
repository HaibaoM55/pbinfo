#include <fstream>
using namespace std;
ifstream fin("frunze.in");
ofstream fout("frunze.out");
int n, nr = 0;
int v[104];
int f[104];
int main(){
    fin >> n;
    nr = n+1;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(v[i] == 0){
            fout << i << '\n';
        }
        f[v[i]]++;
        if(f[v[i]] == 1){
            nr--;
        }
    }
    fout << nr << '\n';
    for(int i = 1; i <= n; i++){
        if(f[i] == 0){
            fout << i << ' ';
        }
    }
    return 0;
}
