#include <fstream>
using namespace std;
ifstream fin("numere2.in");
ofstream fout("numere2.out");
int n, nrzile = 0;
int v[25004], c[25004];
int z = 0;
int main()
{
    fin >> n;
    c[0] = -1;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(v[i] == c[z]){
            z--;
            nrzile++;
        }else{
            z++;
            c[z] = v[i];
        }
    }
    fout << nrzile << '\n';
    for(int i = 1; i <= z; i++){
        fout << c[i] << ' ';
    }
    return 0;
}
