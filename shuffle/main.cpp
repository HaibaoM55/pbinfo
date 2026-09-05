#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("shuffle.in");
ofstream fout("shuffle.out");
int n;
int v[14];
bool b[10][10];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        b[v[i]][v[i-1]] = true;
        b[v[i-1]][v[i]] = true;
    }
    sort(v+1, v+n+1);
    bool exista = false;
    do{
        bool ok = true;
        for(int i = 2; i <= n; i++){
            if(b[v[i]][v[i-1]]){
                ok = false;
                break;
            }
        }
        if(ok){
            exista = true;
            for(int i = 1; i <= n; i++){
                fout << v[i] << ' ';
            }
            fout << '\n';
        }
    }while(next_permutation(v+1, v+n+1));
    if(!exista){
        fout << "nu exista";
    }
    return 0;
}
