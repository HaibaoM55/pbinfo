#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("permutari2.in");
ofstream fout("permutari2.out");
int n;
int v[67];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    sort(v+1, v+n+1);
    do{
        for(int i = 1; i <= n; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
    }while(next_permutation(v+1, v+n+1));
    return 0;
}
