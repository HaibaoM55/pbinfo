#include <fstream>
#include <vector>
using namespace std;
ifstream fin("afisarefii.in");
ofstream fout("afisarefii.out");
int n, m, x;
vector<int> v[104];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v[x].push_back(i);
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        fin >> x;
        int l = v[x].size();
        fout << l << ' ';
        for(int j = 0; j < l; j++){
            fout << v[x][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
