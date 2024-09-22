#include <fstream>
using namespace std;
ifstream fin("lungime1.in");
ofstream fout("lungime1.out");
int n;
int v[100004];
struct nr{
    int inceput = -1, sfarsit = -1;
}f[100004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(f[v[i]].inceput == -1){
            f[v[i]].inceput = i;
        }else{
            f[v[i]].sfarsit = i;
        }
    }
    int vmax = 0;
    for(int i = 1; i <= n; i++){
        if(f[v[i]].sfarsit != -1){
            vmax = max(vmax, f[v[i]].sfarsit-f[v[i]].inceput+1);
        }
    }
    fout << vmax;
    return 0;
}
