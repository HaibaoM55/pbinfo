#include <fstream>
#include <vector>
using namespace std;
ifstream fin("nivelebin.in");
ofstream fout("nivelebin.out");
int n, x, y, z, k;
int vmax=0;
bool esteFiu[1004];
vector<int> v[1004], r[1004];
void visit(int k, int nivel){
    if(k == 0) return;
    vmax = max(vmax, nivel);
    r[nivel].push_back(k);
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        visit(v[k][i], nivel+1);
    }
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x >> y >> z;
        v[i].push_back(y);
        v[i].push_back(z);
        if(y != 0){
            esteFiu[y] = true;
        }
        if(z != 0){
            esteFiu[z] = true;
        }
    }
    int radacina = 1;
    for(int i = 1; i <= n; i++){
        if(!esteFiu[i]){
            radacina = i;
        }
    }
    visit(radacina, 1);
    fout << vmax << '\n';
    for(int i = 1; i <= vmax; i++){
        fout << r[i].size() << ' ';
    }
    return 0;
}
