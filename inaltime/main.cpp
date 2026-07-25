#include <fstream>
#include <vector>
using namespace std;
ifstream fin("inaltime.in");
ofstream fout("inaltime.out");
int n;
int x, y;
vector<int> v[104];
int vmax = 0;
void visit(int k, int nr){
    vmax = max(vmax, nr);
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        visit(v[k][i], nr+1);
    }
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v[x].push_back(i);
    }
    visit(0, 0);
    fout << vmax;
    return 0;
}
